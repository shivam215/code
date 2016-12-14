#include <bits/stdc++.h>
#define MAX 300000
using namespace std;
int tree[MAX][4],sum[100005];
void build_tree(int node, int a, int b) {
  	if(a > b) return; // Out of range

  	if(a == b) { // Leaf node
    		tree[node][sum[a]]++; // Init value
		return;
	}

	build_tree(node*2+1, a, (a+b)/2); // Init left child
	build_tree(node*2+2, 1+(a+b)/2, b); // Init right child

	tree[node][0] = tree[node*2+1][0] + tree[node*2+2][0];
	tree[node][1] = tree[node*2+1][1] + tree[node*2+2][1];
	tree[node][2] = tree[node*2+1][2] + tree[node*2+2][2];

}
void update_tree(int node, int a, int b, int i, int j, int value) {

  	if(tree[node][3] != 0) {
        int val = tree[node][3];
   		int temp = tree[node][0];
        tree[node][0] = tree[node][(0+2*val)%3];
        tree[node][(0+2*val)%3] = tree[node][(0+4*val)%3];
        tree[node][(0+4*val)%3] = temp;

		if(a != b) {
			tree[node*2+1][3] = (tree[node*2+1][3] + tree[node][3])%3; // Mark child as lazy
    			tree[node*2+2][3] = (tree[node*2+2][3] + tree[node][3])%3; // Mark child as lazy
		}

   		tree[node][3] = 0; // Reset it
  	}

	if(a > b || a > j || b < i) // Current segment is not within range [i, j]
		return;

  	if(a >= i && b <= j) { // Segment is fully within range
    		int temp = tree[node][0];
    		tree[node][0] = tree[node][(0+2*value)%3];
    		tree[node][(0+2*value)%3] = tree[node][(0+4*value)%3];
    		tree[node][(0+4*value)%3] = temp;

		if(a != b) { // Not leaf node
			tree[node*2+1][3] = (tree[node*2+1][3] + value)%3;
			tree[node*2+2][3] = (tree[node*2+2][3] + value)%3;
		}

    		return;
	}

	update_tree(node*2+1, a, (a+b)/2, i, j, value); // Updating left child
	update_tree(2+node*2, 1+(a+b)/2, b, i, j, value); // Updating right child

	tree[node][0] = tree[node*2+1][0] + tree[node*2+2][0];
	tree[node][1] = tree[node*2+1][1] + tree[node*2+2][1];
	tree[node][2] = tree[node*2+1][2] + tree[node*2+2][2];
}
int query_tree(int node, int a, int b, int i, int j, int que) {

	if(a > b || a > j || b < i) return 0; // Out of range
	if(tree[node][3] != 0) {
        int val = tree[node][3];
   		int temp = tree[node][0];
        tree[node][0] = tree[node][(0+2*val)%3];
        tree[node][(0+2*val)%3] = tree[node][(0+4*val)%3];
        tree[node][(0+4*val)%3] = temp;

		if(a != b) {
			tree[node*2+1][3] = (tree[node*2+1][3] + tree[node][3])%3; // Mark child as lazy
    			tree[node*2+2][3] = (tree[node*2+2][3] + tree[node][3])%3; // Mark child as lazy
		}

   		tree[node][3] = 0; // Reset it
  	}

	if(a >= i && b <= j) // Current segment is totally within range [i, j]
        return tree[node][que];

	int q1 = query_tree(node*2+1, a, (a+b)/2, i, j,que); // Query left child
	int q2 = query_tree(2+node*2, 1+(a+b)/2, b, i, j,que); // Query right child

	int res = q1+q2;
	return res;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    int i,c,d,type,n,m;
    long long f[3];
    cin>>n>>m;
    char a[n+1];
    cin>>a;
    sum[0] = (a[0]-'0')%3;
    for(i=1;i<n;i++)
    {
        sum[i] = (sum[i-1] + a[i] - '0')%3;
    }
    build_tree(0,0,n-1);
    while(m--)
    {
        cin>>type>>c>>d;
        if(type==1)
        {
            c--;
            int diff = (d - a[c]+'0');
            a[c] = (char)(d);
            diff = (diff + 18)%3;
            if(diff==0)
                continue;
            update_tree(0,0,n-1,c,n-1,diff);
            /*for(i=0;i<9;i++)
    {
        cout<<tree[i][0]<<tree[i][1]<<tree[i][2]<<tree[i][3]<<endl;
    }*/

        }
        else
        {
            c--;d--;
            c--;
            f[0]=0;f[1]=0;f[2]=0;
            if(c==-1){f[0]++;c++;}
            for(i=0;i<3;i++)
            {
                if(c==0)
                    f[i] = f[i] + query_tree(0,0,n-1,0,d,i);
                else
                    f[i] = query_tree(0,0,n-1,c,d,i);
            }
            /*for(i=0;i<9;i++)
    {
        cout<<tree[i][0]<<tree[i][1]<<tree[i][2]<<tree[i][3]<<endl;
    }
            for(i=0;i<3;i++)
                cout<<f[i]<<endl;*/
            long long res=0;
            for(i=0;i<3;i++)
            {
                res = res + (f[i]*(f[i]-1))/2;
            }
        cout<<res<<endl;

        }

    }
    return(0);
}
