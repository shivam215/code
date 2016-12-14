#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long
#define LOGN 20
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int vis[1003],parent[1003],depth[1003],f[1003][LOGN+1];
vector<int> g[1003];
void dfs(int u)
{
    vis[u] = 1;
    if (u != 1) {
        f[u][0] = parent[u];
        for (int i = 1; i <= LOGN; i++)
            f[u][i] = f[f[u][i - 1]][i - 1];
    }
    for(int i=0;i<g[u].size();i++)
    {
        int v = g[u][i];
        if(!vis[v])
        {
            parent[v] = u;
            depth[v] = depth[u]+1;
            dfs(v);
        }
    }

}
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
    int t;
    cin>>t;
    rep(i,1,t+1)
    {
        parent[1] = 1;
        depth[1] = 1;
        memset(vis,0,sizeof(vis));
        rep(l,0,1003)g[l].clear();
        int n;
        cin>>n;
        rep(j,1,n+1)
        {
            int m;
            cin>>m;
            rep(k,0,m)
            {
                int a;
                cin>>a;
                g[j].push_back(a);
                g[a].push_back(j);
            }
        }
        dfs(1);
        int q;
        cin>>q;
        cout<<"Case "<<i<<":"<<endl;
        while(q--)
        {
            int v,w;
        cin>>v>>w;
        cout<<lca(v,w)<<endl;
        }

    }
    return 0;

}
