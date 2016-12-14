#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vpii vector< pii >
#define vpll vector< pll >
#define rep(i,a,b) for(int i=a;i<b;i++)
#define inf 100000000000LL
using namespace std;
vpll g[1000006],gr[1000006];
ll d1[1000006],d2[1000006];
int spt[1000006];
ll p,q;
priority_queue<pll,vector<pll>,greater<pll> > Q;
void transpose()
{
    rep(i,1,p+1)
    {
        rep(j,0,g[i].size())
        {
            gr[g[i][j].first].pb(pii(i,g[i][j].second));
        }
    }
}
void dijkstra1(int src)
{
    memset(spt,0,sizeof(spt));
    Q.push(pii(0,src));
    d1[src]=0;
    //spt[src]=true;
	while(!Q.empty())
	{
		pll tp=Q.top();
		ll v=tp.second, t=tp.first;
		Q.pop();
		spt[v]=1;
        for(int i=0;i<g[v].size();i++)
        {
            ll v2=g[v][i].first, cost=g[v][i].second;
            if(!spt[v2]&&d1[v2]>d1[v]+cost)
            {
                d1[v2]=d1[v]+cost;
                Q.push(pii(d1[v2],v2));
            }
        }
    }
}
void dijkstra2(int src)
{
    memset(spt,0,sizeof(spt));
    Q.push(pii(0,src));
    d2[src]=0;
	while(!Q.empty())
	{
		pll tp=Q.top();
		ll v=tp.second, t=tp.first;
		Q.pop();
		spt[v]=1;
        for(int i=0;i<gr[v].size();i++)
        {
            ll v2=gr[v][i].first, cost=gr[v][i].second;
            if(!spt[v2]&&d2[v2]>d2[v]+cost)
            {
                d2[v2]=d2[v]+cost;
                Q.push(pii(d2[v2],v2));
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>p>>q;
        rep(i,0,1000006){g[i].clear();gr[i].clear();}
        rep(i,0,q)
        {
            ll a,b,c;
            cin>>a>>b>>c;
            g[a].pb(pii(b,c));
        }
        rep(i,0,1000006){d1[i]=inf;d2[i]=inf;}
        while(!Q.empty())Q.pop();
        dijkstra1(1);
        transpose();
        while(!Q.empty())Q.pop();
        dijkstra2(1);
        ll sum=0;
        rep(i,1,p+1)
        {
            sum = sum + d1[i]+d2[i];
        }
        printf("%lld\n",sum);

    }
    return 0;
}
