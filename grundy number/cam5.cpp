#include <bits/stdc++.h>
#define MAX 100005
#define scano(x) scanf("%d",&x)
#define scant(x,y) scanf("%d%d",&x,&y)
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int vis[MAX];
vector<int> adj[MAX];
void dfs(int root)
{
    vis[root]=1;
    rep(i,0,adj[root].size())
    {
        int ch = adj[root][i];
        if(!vis[ch])dfs(ch);
    }
}
int main()
{
    int t;
    scano(t);
    while(t--)
    {
        int n,m;
        scant(n,m);
        rep(i,0,MAX)adj[i].clear();
        rep(i,0,m)
        {
            int a,b;
            scant(a,b);
            adj[a].pb(b);
            adj[b].pb(a);
        }
        int ans=0;
        memset(vis,0,sizeof(vis));
        rep(i,0,n)
        {
            if(!vis[i])
            {
                dfs(i);
                ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
