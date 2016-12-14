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
int n,ans;
int dsp[100005],vis[100005],mark[100005];
vector<int> adj[100005];
pair<int,int> edge[100005];
void bfs()
{
    queue<pii> q;
    q.push(mp(1,0));
    vis[1]=1;
    int utime = 0;
    while(!q.empty())
    {
        int v = q.front().fe;
        int vtime = q.front().se;
        q.pop();
        if(v==n)
        {
            ans = vtime;
            break;
        }
        for(int i=0;i<adj[v].size();i++)
        {
            int e = adj[v][i];
            if(dsp[vtime]!=0)mark[dsp[vtime]]=1;
            if(mark[e])continue;
            int x = edge[e].fe;
            int y = edge[e].se;
            int ch = x;
            if(ch==v)ch=y;
            if(!vis[ch])
            {
                vis[ch]=1;
                q.push(mp(ch,vtime+1));
            }

        }

    }

}
int main()
{
    ios_base::sync_with_stdio(false);
    int m,k;
    cin>>n>>m>>k;
    rep(i,0,m)
    {
        int a,b;
        cin>>a>>b;
        adj[a].pb(i+1);
        adj[b].pb(i+1);
        edge[i+1] = mp(a,b);
    }
    rep(i,0,k)
    {
        int t,x;
        cin>>t>>x;
        if(t<100005)dsp[t]=x;
    }
    ans=-1;
    bfs();
    printf("%d\n",ans);
    return 0;
}
