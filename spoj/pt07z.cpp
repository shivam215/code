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
int vis[10004],dis[10004];
vector<int> adj[10004];
void bfs(int root)
{
    queue<int> q;
    while(!q.empty())q.pop();
    q.push(root);
    vis[root]=1;
    dis[root]=0;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        rep(i,0,adj[u].size())
        {
            int v = adj[u][i];
            if(!vis[v])
            {
                vis[v]=1;
                q.push(v);
                dis[v]=dis[u]+1;
            }
        }
    }
}
int main()
{
    int n;
    cin>>n;
    rep(i,0,n-1)
    {
        int a,b;
        scant(a,b);
        adj[a].pb(b);
        adj[b].pb(a);
    }
    bfs(1);
    int mx=0,in=0;
    rep(i,2,n+1)
    {
        if(dis[i]>mx)
        {
            mx = dis[i];
            in = i;
        }
    }
    memset(dis,0,sizeof(dis));
    memset(vis,0,sizeof(vis));
    bfs(in);
    mx=0;
    rep(i,1,n+1)
    {
        mx = max(mx,dis[i]);
    }
    cout<<mx<<endl;
    return 0;
}

