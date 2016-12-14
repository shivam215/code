#include <bits/stdc++.h>

using namespace std;

const int maxn = 100100;

#define ll long long

struct edge{
	int dest;
	ll wt;
};

vector<edge> adj[maxn];
ll cnt[maxn], sub_cost[maxn], cost[maxn], n;

void dfs1(int node, int parent)
{
	int i;
	cnt[node] = 1;
	for(i=0; i<adj[node].size(); i++){
		if(adj[node][i].dest==parent)
			continue;
		dfs1(adj[node][i].dest, node);
		cnt[node]+=cnt[adj[node][i].dest];
		sub_cost[node]+=(sub_cost[adj[node][i].dest]+(adj[node][i].wt)*cnt[adj[node][i].dest]);
	}
}

void dfs2(int node, int parent)
{
	int i;
	ll c;
	if(parent==-1)
		c = 0;
	else
		c = cost[parent];
	for(i=0; i<adj[node].size(); i++){
		if(adj[node][i].dest==parent)
			continue;
		cost[adj[node][i].dest] = sub_cost[adj[node][i].dest]+ (n-cnt[adj[node][i].dest])*adj[node][i].wt + (cost[node]-sub_cost[adj[node][i].dest]-cnt[adj[node][i].dest]*adj[node][i].wt);
		dfs2(adj[node][i].dest, node);
	}
}

int main()
{
	//freopen("i.txt", "r", stdin);
	int t, u, v, i, j;
	ll w;
	scanf("%d", &t);
	while(t--){
		scanf("%lld", &n);
		for(i=1; i<=n; i++){
			adj[i].clear();
			sub_cost[i] = cnt[i] = cost[i] = 0;
		}
		for(i=0; i<n-1; i++){
			scanf("%d%d%lld", &u, &v, &w);
			adj[u].push_back((edge){v, w});
			adj[v].push_back((edge){u, w});
		}
		dfs1(1, -1);
		for(int i=1;i<=n;i++)cout<<sub_cost[i]<<endl;
		cost[1] = sub_cost[1];
		dfs2(1, -1);
		for(i=1; i<=n; i++);
			//printf("%lld\n", cost[i]);
	}
	return 0;
}
