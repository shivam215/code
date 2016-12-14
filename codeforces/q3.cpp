#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
string s;
int tree[2000000],lazy[2000000];
void build_tree(int node, int a, int b) {
  	if(a > b) return; // Out of range

  	if(a == b) { // Leaf node
    		if(a>0&&s[a]=='.'&&s[a-1]=='.')tree[node]=1;
    		else tree[node]=0;
		return;
	}

	build_tree(node*2, a, (a+b)/2); // Init left child
	build_tree(node*2+1, 1+(a+b)/2, b); // Init right child

	tree[node] = tree[node*2] + tree[node*2+1]; // Init root value
}
void update_tree(int node, int a, int b, int i, int j, int value) {

  	if(lazy[node] != -1) { // This node needs to be updated
   		tree[node] = (b-a+1)*lazy[node]; // Update it

		if(a != b) {
			lazy[node*2] = lazy[node]; // Mark child as lazy
    			lazy[node*2+1] = lazy[node]; // Mark child as lazy
		}

   		lazy[node] = -1; // Reset it
  	}

	if(a > b || a > j || b < i) // Current segment is not within range [i, j]
		return;

  	if(a >= i && b <= j) { // Segment is fully within range
    		tree[node] = (b-a+1)*value;

		if(a != b) { // Not leaf node
			lazy[node*2] = value;
			lazy[node*2+1] = value;
		}

    		return;
	}

	update_tree(node*2, a, (a+b)/2, i, j, value); // Updating left child
	update_tree(1+node*2, 1+(a+b)/2, b, i, j, value); // Updating right child

	tree[node] = tree[node*2] + tree[node*2+1]; // Updating root with max value
}

int query_tree(int node, int a, int b, int i, int j) {

	if(a > b || a > j || b < i) return 0; // Out of range

	if(lazy[node] != -1) { // This node needs to be updated
		tree[node] = (b-a+1)*lazy[node]; // Update it

		if(a != b) {
			lazy[node*2] = lazy[node]; // Mark child as lazy
			lazy[node*2+1] = lazy[node]; // Mark child as lazy
		}

		lazy[node] = -1; // Reset it
	}

	if(a >= i && b <= j) // Current segment is totally within range [i, j]
		return tree[node];

	int q1 = query_tree(node*2, a, (a+b)/2, i, j); // Query left child
	int q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j); // Query right child

    int res = q1 + q2; // Return final result
	return res;
}
int main()
{
    int n,m;
    cin>>n>>m;
    cin>>s;
    build_tree(1,0,n-1);
    memset(lazy,-1,sizeof(lazy));
    while(m--)
    {
        int l,res;
        char ch;
        cin>>l>>ch;
        l--;
        if(s[l]==ch)
        {
            res = query_tree(1,0,n-1,0,n-1);
        }
        else
        {
            s[l] = ch;
            if(l==0)
            {
                if(s[l+1]=='.' && s[l]=='.')
                {
                    update_tree(1,0,n-1,l+1,l+1,1);
                }
                else
                {
                    update_tree(1,0,n-1,l+1,l+1,0);
                }
            }
            else if(l==n-1)
            {
                if(s[l-1]=='.' && s[l]=='.')
                {
                    update_tree(1,0,n-1,l,l,1);
                }
                else
                {
                    update_tree(1,0,n-1,l,l,0);
                }
            }
            else
            {
                if(s[l-1]=='.' && s[l]=='.')
                {
                    update_tree(1,0,n-1,l,l,1);
                }
                else
                {
                    update_tree(1,0,n-1,l,l,0);
                }
                if(s[l+1]=='.' && s[l]=='.')
                {
                    update_tree(1,0,n-1,l+1,l+1,1);
                }
                else
                {
                    update_tree(1,0,n-1,l+1,l+1,0);
                }
            }
            res = query_tree(1,0,n-1,0,n-1);
        }
        cout<<res<<endl;
    }
    return 0;

}
