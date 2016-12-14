#include <bits/stdc++.h>
#define inf 10000000
#define mod 1000000007
#define scano(x) scanf("%d",&x)
#define scanll(x) scanf("%lld",&x)
#define scant(x,y) scanf("%d%d",&x,&y)
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define piii pair<int,pii >
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fe first
#define se second
using namespace std;
int dis[505][24];
priority_queue<piii,vector<piii>,greater<piii> > q;
vector<pii > adj[505];
int tim[2003][30],ans[24][505];
void dijkstra(int start)
{
    for(int i=0;i<505;i++)for(int j=0;j<24;j++)dis[i][j]=inf;
    while(!q.empty())q.pop();
    dis[1][start]=0;
    q.push(mp(0,mp(1,start)));
    while(!q.empty())
    {
        int u = q.top().se.fe;
        int ucost = q.top().fe;
        int endtime = q.top().se.se;
        q.pop();
        if(ucost>dis[u][endtime])continue;
        for(int i=0; i<adj[u].size(); i++)
        {
            int v=adj[u][i].fe;
            int edge = adj[u][i].se;
            int vcost = tim[edge][endtime];
            int vendtime = (endtime + vcost)%24;
            if(dis[v][vendtime]>dis[u][endtime]+vcost)
            {
                dis[v][vendtime]=dis[u][endtime]+vcost;
                q.push(mp(dis[v][vendtime],mp(v,vendtime)));
            }
        }

    }
}

int main()
{
    freopen("q1l.in","r",stdin);
    freopen("q1l.out","w",stdout);
    int t;
    scano(t);
    rep(test,1,t+1)
    {
        int n,m,k;
        scant(n,m);
        scano(k);
        for(int i=0;i<5005;i++)adj[i].clear();
        for(int i=0;i<m;i++)
        {
            int a,b;
            scant(a,b);
            adj[a].pb(mp(b,i));
            adj[b].pb(mp(a,i));
            rep(j,0,24)
            {
                scano(tim[i][j]);
            }
        }
        for(int i=0;i<24;i++)
        {
            dijkstra(i);
            for(int j=1;j<=n;j++)
            {
                int res=inf;
                for(int l=0;l<24;l++)
                {
                    res = min(res,dis[j][l]);
                }
                ans[i][j]=res;
            }
        }
        printf("Case #%d: ",test);
        rep(h,1,k+1)
        {
            int a,b;
            scant(a,b);
            if(ans[b][a]>=inf)printf("-1 ");
            else printf("%d ",ans[b][a]);
        }
        printf("\n");

    }
}
