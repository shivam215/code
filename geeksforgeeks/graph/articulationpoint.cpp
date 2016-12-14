#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
vector<int> g[100];
int ap[100],vis[100],disc[100],low[100],parent[100];
void dfs(int root)
{
    static int time=0;
    vis[root]=1;
    disc[root]=low[root]=++time;
    int children=0;
    rep(i,0,g[root].size())
    {
        int child = g[root][i];
        if(!vis[child])
        {
            children++;
            parent[child]=root;
            dfs(child);
            low[root] = min(low[root],low[child]);
            if(parent[root]==-1 && children>1)ap[root]=1;
            if(parent[root]!=-1 && low[child]>=disc[root])ap[root]=1;
        }
        else if(child!=parent[root])
        {
            low[root] = min(low[root],disc[child]);
        }
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    rep(i,0,e)
    {
        int a,b;
        cin>>a>>b;
        g[a].pb(b);
        g[b].pb(a);
    }
    memset(parent,-1,sizeof(parent));
    memset(vis,0,sizeof(vis));
    rep(i,0,n)if(!vis[i])dfs(i);
    rep(i,0,n)
    {
        if(ap[i])cout<<i<<' ';
    }
    cout<<endl;
    return 0;

}
