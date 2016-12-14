#include <bits/stdc++.h>
#define inf 1000000000000LL
#define scanint(x) scanf("%d",&x)
#define scanll(x) scanf("%lld",&x)
#define pb push_back
#define mp make_pair
#define ll long long
#define pll pair<ll,ll>
#define plll pair< ll,pll >
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int ans[10004],spt[10004];
ll d1[102][102];
priority_queue<plll,vector< plll >,greater<plll> > Q;
vector<plll> g[102];
void dijkstra1(int beg,int src)
{
    memset(spt,0,sizeof(spt));
    for(int i=0;i<102;i++)for(int j=0;j<102;j++)d1[i][j]=inf;
    Q.push(plll(0,pll(src,-1)));
    d1[beg][src]=0;
	while(!Q.empty())
	{
		plll tp=Q.top();
		ll v=tp.second.first, t=tp.first;
		ll edge1 = tp.second.second;
		Q.pop();
		if(edge1!=-1)spt[edge1]=1;
		if(t>d1[beg][v])continue;
		if(edge1!=-1)ans[edge1]=-1;
        for(int i=0;i<g[v].size();i++)
        {
            ll v2=g[v][i].first, cost=g[v][i].second.first;
            ll edge = g[v][i].second.second;
            if(!spt[edge]&&d1[beg][v2]>=d1[beg][v]+cost)
            {
                d1[beg][v2]=d1[beg][v]+cost;
                Q.push(plll(d1[beg][v2],pll(v2,edge)));
            }
        }
    }
}
int main()
{
    freopen("C-large-practice.in","r",stdin);
    freopen("C-large-practice.out","w",stdout);
    int t;
    cin>>t;
    rep(test,1,t+1)
    {
        ll n,m;
        cin>>n>>m;
        for(int i=0;i<102;i++)g[i].clear();
        for(int i=0;i<m;i++)
        {
            ll a,b,c;
            cin>>a>>b>>c;
            g[a].pb(mp(b,mp(c,i)));
            g[b].pb(mp(a,mp(c,i)));
        }
        memset(ans,0,sizeof(ans));
        //dijkstra1(0,0);
        for(int i=0;i<n;i++)
        {
            dijkstra1(i,i);
        }
        printf("Case #%d:\n",test);
        for(int i=0;i<m;i++)
        {
            if(ans[i]==0)
            {
                cout<<i<<endl;
            }
        }

    }
    return 0;
}
