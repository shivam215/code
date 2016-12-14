#include <bits/stdc++.h>
#define ll long long
#define inf 300000
using namespace std;
vector<ll> adj[202];
set<ll> s;
ll m[202][202];
ll dp[2][202];
ll a[200005];
ll vis[202];
ll n,mp;
ll mn[202];
void dfs(ll x,ll root)
{
    vis[x]=1;
    for(ll i=0;i<adj[x].size();i++)
    {
        ll y = adj[x][i];
        if(!vis[y])
        {
            dfs(y,root);
        }
    }
    m[root][x]=1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    ll k,x,y,z,i,j;
    scanf("%d",&t);
    while(t--)
    {
        for(i=0;i<202;i++)adj[i].clear();
        memset(m,0,sizeof(m));
        scanf("%lld%lld%lld",&mp,&k,&n);
        s.clear();
        while(k--)
        {
            scanf("%lld%lld",&x,&y);
            adj[x].push_back(y);
            adj[y].push_back(x);
            s.insert(x);
            s.insert(y);
        }
        for(set<ll>::iterator it=s.begin();it!=s.end();it++)
        {
            memset(vis,0,sizeof(vis));
            dfs(*it,*it);
        }
        //for(i=1;i<=mp;i++){for(ll j=1;j<=mp;j++)cout<<m[i][j]<<' ';cout<<endl;}
        for(i=0;i<n;i++)scanf("%lld",&a[i]);
        mn[0]=inf;
        for(i=1;i<=mp;i++)
        {
            if(a[0]==i)dp[0][i]=0;
            else if(m[a[0]][i]==1)dp[0][i]=1;
            else dp[0][i]=inf;
            mn[i] = min(mn[i-1],dp[0][i]);
        }
        for(i=1;i<=n-1;i++)
        {
            for(j=1;j<=mp;j++)
            {
                if(a[i]==j)dp[i&1][j] = mn[j];
                else if(m[a[i]][j]==1)dp[i&1][j] = mn[j]+1;
                else dp[i&1][j]=inf;
                mn[j] = dp[i&1][j];
                if(mn[j-1]<mn[j])mn[j]=mn[j-1];
            }
        }
        ll cnt=inf;
        for(i=1;i<=mp;i++)
        {
            cnt = min(cnt,dp[(n-1)&1][i]);
        }
        if(cnt>=inf)printf("-1\n");
        else printf("%lld\n",cnt);
    }
    return 0;
}
