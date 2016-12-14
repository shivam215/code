#include <bits/stdc++.h>
#define inf 1000000000
#define mod 1000000007
#define scano(x) scanf("%d",&x)
#define scanll(x) scanf("%lld",&x)
#define scant(x,y) scanf("%d%d",&x,&y)
#define pb push_back
#define mp make_pair
#define ll long long int
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fe first
#define se second
#define MAX 1000006
using namespace std;
int dp[10004];
priority_queue<pii,vector<pii>,greater<pii> > q;
vector<pair<int,int> > adj[10004];
void dijkstra(int src,int dest)
{
    for(int i=0;i<10004;i++)dp[i]=inf;
    //while(!q.empty())q.pop();
    dp[src]=0;
    q.push(mp(0,src));
    while(!q.empty())
    {
        int u = q.top().se;
        if(u==dest)break;
        int ucost = q.top().fe;
        q.pop();
        if(ucost>dp[u])continue;
        for(int i=0; i<adj[u].size(); i++)
        {
            int v=adj[u][i].fe, vcost=adj[u][i].se;
            if(dp[v]>dp[u]+vcost)
            {
                dp[v]=dp[u]+vcost;
                q.push(mp(dp[v],v));
            }
        }

    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    rep(i,0,m)
    {
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].pb(mp(b,c));
        adj[b].pb(mp(a,c));
    }
    dijkstra(1,3);
    rep(i,1,n+1)printf("%d ",dp[i]);
    cout<<endl;
    return 0;
}
