#include <bits/stdc++.h>
#define inf 1000000000000000000LL
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
#define MAX 100005
using namespace std;
int par[MAX],rnk[MAX],deg[MAX];
vector<pii > edge;
vector<int> v[MAX],ans;
struct DS
{
    DS()
    {
        rep(i,0,MAX)par[i]=i,rnk[i]=0;
    }
    int get(int i)
    {
        if(par[i]==i)return i;
        return par[i]=get(par[i]);
    }
    void join(int i,int j)
    {
        int x = get(i);
        int y = get(j);
        if(x==y) return;
        if(rnk[x]<rnk[y])par[x]=y;
        else if(rnk[x]>rnk[y])par[y]=x;
        else
        {
            par[x]=y;
            rnk[y]++;
        }
    }
};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        edge.clear();
        rep(i,0,n+1)deg[i]=0;
        rep(i,0,m)
        {
            int a,b;
            cin>>a>>b;
            edge.pb(mp(a,b));
            deg[a]++,deg[b]++;
        }
        rep(i,0,n)v[i].clear();
        rep(i,0,edge.size())
        {
            v[deg[edge[i].fe]].pb(i);
            v[deg[edge[i].se]].pb(i);
        }
        DS ds;
        ans.clear();
        ans.pb(n-1);
        int tot=n;
        for(int i=n-2;i>=0;i--)
        {
            rep(j,0,v[i+1].size())
            {
                int a = edge[v[i+1][j]].fe;
                int b = edge[v[i+1][j]].se;
                if(deg[a]<i+1 || deg[b]<i+1)continue;
                //cout<<i+1<<' '<<a<<' '<<b<<endl;
                int x = ds.get(a);
                int y = ds.get(b);
                if(x!=y)
                {
                    ds.join(x,y);
                    tot--;
                }
            }
            //cout<<tot-1<<endl;
            ans.pb(tot-1);
        }
        for(int i=n-1;i>=0;i--)
        {
            if(i>0)printf("%d ",ans[i]);
            else printf("%d\n",ans[i]);
        }
    }
    return 0;
}
