#include <bits/stdc++.h>
#define inf 1000000000012LL
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int lazy[2097200];
ll tree[2097200];
void update_tree(int node, int a, int b, int i, int j, int value) {

  	if(lazy[node] != 0) { // This node needs to be updated
   		tree[node] += (b-a+1)*lazy[node]; // Update it

		if(a != b) {
			lazy[node*2] += lazy[node]; // Mark child as lazy
    			lazy[node*2+1] += lazy[node]; // Mark child as lazy
		}

   		lazy[node] = 0; // Reset it
  	}

	if(a > b || a > j || b < i) // Current segment is not within range [i, j]
		return;

  	if(a >= i && b <= j) { // Segment is fully within range
    		tree[node] += (b-a+1)*value;

		if(a != b) { // Not leaf node
			lazy[node*2] += value;
			lazy[node*2+1] += value;
		}

    		return;
	}

	update_tree(node*2, a, (a+b)/2, i, j, value); // Updating left child
	update_tree(1+node*2, 1+(a+b)/2, b, i, j, value); // Updating right child

	tree[node] = tree[node*2] + tree[node*2+1]; // Updating root with max value
}

ll query_tree(int node, int a, int b, int i, int j) {

	if(a > b || a > j || b < i) return 0; // Out of range

	if(lazy[node] != 0) { // This node needs to be updated
		tree[node] += (b-a+1)*lazy[node]; // Update it

		if(a != b) {
			lazy[node*2] += lazy[node]; // Mark child as lazy
			lazy[node*2+1] += lazy[node]; // Mark child as lazy
		}

		lazy[node] = 0; // Reset it
	}

	if(a >= i && b <= j) // Current segment is totally within range [i, j]
		return tree[node];

	ll q1 = query_tree(node*2, a, (a+b)/2, i, j); // Query left child
	ll q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j); // Query right child

    ll res = q1 + q2; // Return final result
	return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t,n,h,i,l,r;
    cin>>t;
    while(t--)
    {
       cin>>n>>h;
       int L = log2(n) + 1;
       int MAX = 2*(1<<L) - 1;
       for(i=0;i<=MAX;i++){tree[i]=0;lazy[i]=0;}
       for(i=0;i<n;i++)
       {
           cin>>l>>r;
           update_tree(1,0,n-1,l,r,1);
       }
       ll ans = inf;
       for(i=0;i<n-h+1;i++)
       {
           ll res = query_tree(1,0,n-1,i,i+h-1);
           res = 1LL*n*h - res;
           if(res<ans)ans=res;
       }
       printf("%lld\n",ans);
    }
    return 0;
}
