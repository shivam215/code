#include <bits/stdc++.h>
#define pb push_back
#define mod 19101995
#define ll long long
using namespace std;
vector<ll> g[101010],child[101010];
ll n,mx;
ll dp[101010][100];
int vis[101010];
void dfs(ll x)
{
    vis[x]=1;
    for(ll i=0;i<g[x].size();i++)
    {
        if(!vis[g[x][i]])
        {
            dfs(g[x][i]);
            child[x].pb(g[x][i]);
        }
    }
}
long long solve(ll i, ll cnt)
{
    if(cnt>mx)return 0;
    ll &ret = dp[i][cnt];
    if(ret!=-1)return ret;
    ret=0;
    ll ch = child[i].size();
    if(ch==0)return ret=1;
    ll a[ch],b[ch];
    ll temp=1;
    for(ll j=0;j<ch;j++)
    {
        temp = (temp*solve(child[i][j],cnt+1))%mod;
        a[j]=temp;
    }
    temp=1;
    for(ll j=ch-1;j>=0;j--)
    {
        temp = (temp*solve(child[i][j],cnt+1))%mod;
        b[j]=temp;
    }
    for(ll j=0;j<ch;j++)
    {
        ll cur=1;
        if(j>0)cur = (cur*a[j-1])%mod;
        if(j<ch-1)cur = (cur*b[j+1])%mod;
        cur = (cur*solve(child[i][j],cnt))%mod;
        ret = (ret+cur)%mod;
    }
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin>>n;
    mx = log2(n);
    for(ll i=1;i<n;i++)
    {
        ll x,y;
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }
    memset(dp,-1,sizeof(dp));
    //memset(vis,0,sizeof(vis));
    dfs(1);
    cout<<solve(1,0)<<endl;
    return 0;
}
