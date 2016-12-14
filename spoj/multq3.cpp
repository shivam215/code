#include <bits/stdc++.h>
#define MAX 2000000
#define scanint(x) scanf("%d",&x)
#define scanll(x) scanf("%lld",&x)
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int tree[MAX][4];
void build_tree(int node, int a, int b) {
  	if(a > b) return; // Out of range

  	if(a == b) { // Leaf node
    		tree[node][0]++; // Init value
		return;
	}

	build_tree(node*2+1, a, (a+b)/2); // Init left child
	build_tree(node*2+2, 1+(a+b)/2, b); // Init right child

	tree[node][0] = tree[node*2+1][0] + tree[node*2+2][0];

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
    int n,q;
    scanint(n);
    scanint(q);
    build_tree(1,0,n-1);
    while(q--)
    {
        int type,l,r;
        scanint(type);
        scanint(l);
        scanint(r);
        if(type==0)
        {
            update_tree(1,0,n-1,l,r,1);
        }
        else
        {
            int res = query_tree(1,0,n-1,l,r,0);
            printf("%d\n",res);
        }
    }
    return 0;
}
