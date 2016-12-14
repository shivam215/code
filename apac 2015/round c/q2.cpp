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
#define piiii pair<pii,pii>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fe first
#define se second
using namespace std;
priority_queue<piiii,vector<piiii>,greater<piiii> > que;
int flag[105],dis[105][1003],vis[105][1003],w[105],s[105];
vector< piiii > adj[105][1003];
void dijkstra(int a,int b,int fx,int fy)
{
    memset(vis,0,sizeof(vis));
    rep(i,0,105)rep(j,0,1003)dis[i][j]=inf;
    memset(flag,0,sizeof(flag));
    while(!que.empty())que.pop();
    que.push(mp(mp(0,-1),mp(a,b)));
    dis[a][b]=0;
    vis[a][b]=1;
	while(!que.empty())
	{
		piiii tp = que.top();
		a = tp.se.fe;
		b = tp.se.se;
		//cout<<a<<' '<<b<<endl;
		if(a==fx&&b==fy)break;
		int th = tp.fe.se;
		if(th==0||th==-1)flag[a]=1;
		else flag[a]=0;
		//cout<<flag[a]<<' '<<tp.fe.fe<<endl;
		que.pop();
		int ucost = tp.fe.fe;
		vis[a][b]=1;
        for(int i=0;i<adj[a][b].size();i++)
        {
            int c = adj[a][b][i].fe.fe,d=adj[a][b][i].fe.se;
            //if(a==1&&b==4)cout<<c<<' '<<"hey"<<' '<<d<<endl;
            int cost=adj[a][b][i].se.fe;
            int type=adj[a][b][i].se.se;
            if(type==1)
            {
                if(flag[c]==1)cost = cost + w[c];
            }
            //if(c==1&&d==5)cout<<"shi"<<' '<<cost<<endl;
                if(!vis[c][d]&&dis[c][d]>ucost+cost)
                {
                    dis[c][d]=ucost+cost;
                que.push(mp(mp(dis[c][d],type),mp(c,d)));
                }

        }
    }
}
int main()
{
    freopen("q2s.in","r",stdin);
    freopen("q2s.out","w",stdout);
    int t;
    cin>>t;
    rep(test,1,t+1)
    {
        int n,m;
        scano(n);
        rep(i,0,105)rep(j,0,1003)adj[i][j].clear();
        for(int i=1;i<=n;i++)
        {
            cin>>s[i]>>w[i];
            for(int j=1;j<s[i];j++)
            {
                int temp;
                scano(temp);
                adj[i][j].pb(mp(mp(i,j+1),mp(temp,1)));
                adj[i][j+1].pb(mp(mp(i,j),mp(temp,1)));
            }
        }
        scano(m);
        while(m--)
        {
            int a,b,c,d,e;
            cin>>a>>b>>c>>d>>e;
            adj[a][b].pb(mp(mp(c,d),mp(e,0)));
            adj[c][d].pb(mp(mp(a,b),mp(e,0)));
        }
        int q;
        scano(q);
        printf("Case #%d:\n",test);
        while(q--)
        {
            int a,b,c,d;
            cin>>a>>b>>c>>d;
            dijkstra(a,b,c,d);
            if(dis[c][d]>=inf)
            {
                cout<<-1<<endl;
            }
            else
            {
                cout<<dis[c][d]<<endl;
            }
        }
    }
    return 0;
}
