#include <bits/stdc++.h>
using namespace std;
int tree[26][300000],lazy[26][300000];
string arr;
void build_tree(int node,int l, int a, int b) {
  	if(a > b) return; // Out of range

  	if(a == b) {
            if(arr[a]-'a'==l)tree[l][node]=1;
            else tree[l][node]=0;
		return;
	}

	build_tree(node*2, l, a, (a+b)/2); // Init left child
	build_tree(node*2+1, l, 1+(a+b)/2, b); // Init right child

	tree[l][node] = (tree[l][node*2] + tree[l][node*2+1]); // Init root value
}
void update_tree(int node, int l, int a, int b, int i, int j, int value) {

  	if(lazy[l][node] != -1) { // This node needs to be updated
   		tree[l][node] = (b-a+1)*lazy[l][node]; // Update it

		if(a != b) {
			lazy[l][node*2] = lazy[l][node]; // Mark child as lazy
    			lazy[l][node*2+1] = lazy[l][node]; // Mark child as lazy
		}

   		lazy[l][node] = -1; // Reset it
  	}

	if(a > b || a > j || b < i) // Current segment is not within range [i, j]
		return;

  	if(a >= i && b <= j) { // Segment is fully within range
    		tree[l][node] = (b-a+1)*value;

		if(a != b) { // Not leaf node
			lazy[l][node*2] = value;
			lazy[l][node*2+1] = value;
		}

    		return;
	}

	update_tree(node*2, l, a, (a+b)/2, i, j, value); // Updating left child
	update_tree(1+node*2, l, 1+(a+b)/2, b, i, j, value); // Updating right child

	tree[l][node] = (tree[l][node*2] + tree[l][node*2+1]); // Updating root with max value
}

int query_tree(int node, int l, int a, int b, int i, int j) {

	if(a > b || a > j || b < i) return 0; // Out of range

	if(lazy[l][node] != -1) { // This node needs to be updated
		tree[l][node] = (b-a+1)*lazy[l][node]; // Update it

		if(a != b) {
			lazy[l][node*2] = lazy[l][node]; // Mark child as lazy
			lazy[l][node*2+1] = lazy[l][node]; // Mark child as lazy
		}

		lazy[l][node] = -1; // Reset it
	}

	if(a >= i && b <= j) // Current segment is totally within range [i, j]
		return tree[l][node];

	int q1 = query_tree(node*2, l, a, (a+b)/2, i, j); // Query left child
	int q2 = query_tree(1+node*2, l, 1+(a+b)/2, b, i, j); // Query right child

	int res = (q1 + q2); // Return final result

	return res;
}
int main()
{
    int n,q,i,j,k,a,b;
    cin>>n>>q;
    cin>>arr;
    memset(lazy,-1,sizeof(lazy));
    for(i=0;i<26;i++) build_tree(1,i,0,n-1);
    //for(i=0;i<26;i++)cout<<query_tree(1,i,0,n-1,3,7)<<endl;
    while(q--)
    {
        cin>>a>>b>>k;
        a--;b--;
        if(k==1)
        {
            j=a;
            for(i=0;i<26;i++)
            {
                int coun = query_tree(1,i,0,n-1,a,b);
                if(coun>0)
                {
                    update_tree(1,i,0,n-1,a,b,0);
                    update_tree(1,i,0,n-1,j,j+coun-1,1);
                }
                j = j + coun;

            }
        }
        else
        {
            j=a;
            for(i=25;i>=0;i--)
            {
                int coun = query_tree(1,i,0,n-1,a,b);
                if(coun>0)
                {
                    update_tree(1,i,0,n-1,a,b,0);
                    update_tree(1,i,0,n-1,j,j+coun-1,1);
                }
                j = j + coun;

            }

        }
    }
    string str;
    for(i=0;i<n;i++)
    {
        for(j=0;j<26;j++)
        {
            int res = query_tree(1,j,0,n-1,i,i);
            if(res==1)break;
        }
        str = str + char(j+'a');
    }
    cout<<str<<endl;
    return 0;

}
