#include <bits/stdc++.h>
#define inf 1000000000
#define mod 1000000007
#define scano(x) scanf("%d",&x)
#define scanll(x) scanf("%lld",&x)
#define scant(x,y) scanf("%d%d",&x,&y)
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fe first
#define se second
using namespace std;
int dis[10004];
priority_queue<pii,vector<pii>,greater<pii> > q;
vector<pii > adj[10004];
void dijkstra(int src,int dest)
{
    for(int i=0;i<10004;i++)dis[i]=inf;
    while(!q.empty())q.pop();
    dis[src]=0;
    q.push(mp(0,src));
    while(!q.empty())
    {
        int u = q.top().se;
        if(u==dest)break;
        int ucost = q.top().fe;
        q.pop();
        if(ucost>dis[u])continue;
        for(int i=0; i<adj[u].size(); i++)
        {
            int v=adj[u][i].fe, vcost=adj[u][i].se;
            if(dis[v]>dis[u]+vcost)
            {
                dis[v]=dis[u]+vcost;
                q.push(mp(dis[v],v));
            }
        }

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
        rep(i,0,10004)adj[i].clear();
        rep(i,0,m)
        {
            int a,b,c;
            scant(a,b);
            scano(c);
            adj[a].pb(mp(b,c));
        }
        int l,r;
        scant(l,r);
        dijkstra(l,r);
        if(dis[r]>=inf)printf("NO\n");
        else printf("%d\n",dis[r]);
    }
    return 0;
}
