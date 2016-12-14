#include <bits/stdc++.h>
#define inf 100000000000LL
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
#define MAX 10004
using namespace std;
vector<int> g[MAX];
ll a[MAX],m;
int n,k;
ll dp[MAX][303];
ll solve(int u,int c)
{
    if(dp[u][c]!=-inf)return dp[u][c];
    ll res1=-inf,res2=-inf,res;
    int flag=0;
    for(int i=0; i<g[u].size(); i++)
    {
        flag=1;
        int ch = g[u][i];
        res1 = max(res1,a[u]+solve(ch,c));
        if(c+1<=k)res2 = max(res2,m*a[u]+solve(ch,c+1));
    }
    res1 = max(res1,a[u]);
    if(c+1<=k)res2 = max(res2,m*a[u]);
    res = max(res1,res2);
    if(flag==0)
    {
        if(c<k&&a[u]>0)return dp[u][c]=a[u]*m;
        return dp[u][c]=a[u];
    }
    return dp[u][c]=res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
    cin>>n>>m>>k;
    rep(i,0,n)cin>>a[i];
    rep(i,0,n)g[i].clear();
    rep(i,0,n-1)
    {
        int c,d;
        cin>>c>>d;
        g[c].pb(d);
    }
    rep(i,0,n+1)rep(j,0,k+1)dp[i][j]=-inf;
    ll res=-inf;
    rep(i,0,n)
    {
        res = max(res,solve(i,0));
    }
    printf("%lld\n",res);
    }
    return 0;
}
