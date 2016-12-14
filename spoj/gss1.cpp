#include <bits/stdc++.h>
#define scano(x) scanf("%d",&x)
#define scant(x,y) scanf("%d%d",&x,&y)
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define piiii pair< pii,pii >
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int tree[4][4*50000],arr[50004];
void build_tree(int node, int a, int b) {
    if(a > b) return;

  	if(a == b) { // Leaf node
    		tree[0][node] = arr[a];
    		tree[1][node]=arr[a];
    		tree[2][node]=arr[a];
    		tree[3][node]=arr[a];
		return;
	}

	build_tree(node*2, a, (a+b)/2); // Init left child
	build_tree(node*2+1, 1+(a+b)/2, b); // Init right child

	tree[0][node] = max(tree[0][2*node],tree[2][node*2]+tree[0][node*2+1]);
	tree[1][node] = max(tree[1][2*node+1],tree[2][node*2+1]+tree[1][node*2]);
	tree[2][node] = tree[2][2*node] + tree[2][2*node+1];
	tree[3][node] = max(tree[3][node*2],max(tree[3][node*2+1],tree[1][node*2]+tree[0][node*2+1]));
}

piiii query_tree(int i,int si,int sj,int qi,int qj){
	if(si==qi and sj==qj){
            return piiii(pii(tree[0][i],tree[1][i]),pii(tree[2][i],tree[3][i]));
	}
	int mid = (si+sj)/2;
	if(qj<=mid)
		return query_tree(2*i,si,mid,qi,qj);
	else
		if(mid+1<=qi)
			return query_tree(2*i+1,mid+1,sj,qi,qj);
	else
	{
	    piiii a = query_tree(2*i,si,mid,qi,mid);
	    piiii b = query_tree(2*i+1,mid+1,sj,mid+1,qj);
	    piiii ans;
	    ans.first.first = max(a.first.first,a.second.first+b.first.first);
	    ans.first.second = max(b.first.second,b.second.first+a.first.second);
	    ans.second.first = a.second.first + b.second.first;
	    ans.second.second = max(a.second.second,max(b.second.second,a.first.second+b.first.first));
	    return ans;

	}
}
int main()
{
    int n,m;
    scano(n);
    rep(i,0,n)cin>>arr[i];
    build_tree(1,0,n-1);
    scano(m);
    while(m--)
    {
        int l,r;
        scant(l,r);
        l--;r--;
        piiii ans = query_tree(1,0,n-1,l,r);
        printf("%d\n",ans.second.second);
    }
    return 0;
}
