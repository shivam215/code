#include <bits/stdc++.h>
#define MAX 300000
#define LOGN 20
using namespace std;
int vis[100005];
vector< pair<int,int> > adj[100005];
map< pair<int,int>,int > p;
int m[100005],parent[100005],depth[100005],pos[100005],dfsorder[100005],cost[100005],siz[100005],P[100005],f[100005][LOGN+1];
int tree[MAX],len,n,nr=20,lazy[MAX];
pair<int,int> edge[100005];
void dfs(int u)
{
    dfsorder[++len] = u;
    pos[u] = len;
    vis[u] = 1;
    if (u != 1) {
        f[u][0] = parent[u];
        for (int i = 1; i <= LOGN; i++)
            f[u][i] = f[f[u][i - 1]][i - 1];
    }
    siz[u] =1;
    for(int i=0;i<adj[u].size();i++)
    {
        int v = adj[u][i].first;
        if(!vis[v])
        {
            parent[v] = u;
            depth[v] = depth[u]+1;
            cost[v] = cost[u] + adj[u][i].second;
            dfs(v);
            siz[u]+=siz[v];
        }
    }

}
int dfs2(int node)
{
    if(depth[node]<nr)P[node]=1;
    else
    {
        if(!depth[node]%nr)P[node]=parent[node];
        else P[node] = P[parent[node]];
    }
    vis[node]=1;
    if(adj[node].size()==0)return 1;
    int height=0;
    for(int i=0;i<adj[node].size();i++)
    {
        int v = adj[node][i].first;
        if(!vis[v])
        {
            height = max(height,dfs2(v));
        }
    }
    return height+1;

}
void update_tree(int node, int a, int b, int i, int j, int value) {

  	if(lazy[node] != 0) { // This node needs to be updated
   		tree[node] += lazy[node]; // Update it

		if(a != b) {
			lazy[node*2] += lazy[node]; // Mark child as lazy
    			lazy[node*2+1] += lazy[node]; // Mark child as lazy
		}

   		lazy[node] = 0; // Reset it
  	}

	if(a > b || a > j || b < i) // Current segment is not within range [i, j]
		return;

  	if(a >= i && b <= j) { // Segment is fully within range
    		tree[node] += value;

		if(a != b) { // Not leaf node
			lazy[node*2] += value;
			lazy[node*2+1] += value;
		}

    		return;
	}

	update_tree(node*2, a, (a+b)/2, i, j, value); // Updating left child
	update_tree(1+node*2, 1+(a+b)/2, b, i, j, value); // Updating right child

	tree[node] = (tree[node*2]+tree[node*2+1]); // Updating root with max value
}

/**
 * Query tree to get max element value within range [i, j]
 */
int query_tree(int node, int a, int b, int i, int j) {

	if(a > b || a > j || b < i) return 0; // Out of range

	if(lazy[node] != 0) { // This node needs to be updated
		tree[node] += lazy[node]; // Update it

		if(a != b) {
			lazy[node*2] += lazy[node]; // Mark child as lazy
			lazy[node*2+1] += lazy[node]; // Mark child as lazy
		}

		lazy[node] = 0; // Reset it
	}

	if(a >= i && b <= j) // Current segment is totally within range [i, j]
		return tree[node];

	int q1 = query_tree(node*2, a, (a+b)/2, i, j); // Query left child
	int q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j); // Query right child

	int res = (q1+q2); // Return final result

	return res;
}


/*int lca(int x, int y)
{
    while(P[x]!=P[y])
    {
        if(depth[x]>depth[y])x=P[x];
        else y = P[y];
    }
    while(x!=y)
    {
        if(depth[x]>depth[y])x=parent[x];
        else y = parent[y];
    }
    return x;

}*/
int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);

    for (int i = LOGN; i >= 0; i--)
        if (depth[f[u][i]] >= depth[v]) u = f[u][i];

    if (u == v) return v;

    for (int i = LOGN; i >= 0; i--)
        if (f[u][i] != f[v][i]) {
            u = f[u][i];
            v = f[v][i];
        }

    return f[u][0];
}
int main()
{
    ios_base::sync_with_stdio(false);
    int i,x,y,q,u,v,w,type;
    scanf("%d",&n);
    for(i=1;i<n;i++)
    {
        scanf("%d%d%d",&u,&v,&m[i]);
        adj[u].push_back(make_pair(v,m[i]));
        adj[v].push_back(make_pair(u,m[i]));
        edge[i] = make_pair(u,v);
    }
    parent[1] = 1;
    depth[1] = 1;
    cost[1] = 0;
    len=0;
    dfs(1);
    //build_tree(1,1,n);
    memset(vis,0,sizeof(vis));
    int h = dfs2(1);
    nr = sqrt(h);
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d%d%d",&type,&x,&y);
        if(type==1)
        {
            int diff = y-m[x];
            m[x] = y;
            u = edge[x].first;
            v = edge[x].second;
            if(parent[u]!=v)swap(u,v);
            update_tree(1,1,n,pos[u],pos[u]+siz[u]-1,diff);
        }
        else
        {
           int p = lca(x,y);
           int res = query_tree(1,1,n,pos[x],pos[x])+cost[x]+cost[y]-2*cost[p]+query_tree(1,1,n,pos[y],pos[y])- 2*query_tree(1,1,n,pos[p],pos[p]);
           printf("%d\n",res);
        }
    }
    return 0;
}
