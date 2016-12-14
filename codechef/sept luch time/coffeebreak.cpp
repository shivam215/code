#include <bits/stdc++.h>
#define inf 10000000000000000LL
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
ll dp[202][202][202];
map< pair<pii,int>,ll > ma;
ll a[5003];
int n,k,d;
ll m;
ll solve(int i,int prev,int tot)
{
    if(i==n)
    {
        if(tot==k)return 0;
        return -inf;
    }
    if(prev!=-1)
    {if(dp[i][prev][tot]!=-inf)return dp[i][prev][tot];}
    ll res=-inf;
    if(prev!=-1)
    {
        if(i-prev<=d)res=max(res,a[i]*m+solve(i+1,prev,tot));
        else res = max(res,a[i]+solve(i+1,prev,tot));
    }
    else
    {
        res = max(res,a[i]+solve(i+1,prev,tot));
    }

    if(tot+1<=k)res = max(res,solve(i+1,i,tot+1));
    if(prev!=-1)dp[i][prev][tot]=res;
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>k>>d>>m;
        rep(i,0,n)cin>>a[i];
        rep(i,0,n+1)rep(j,0,n+1)rep(p,0,k+1)dp[i][j][p]=-inf;
        ll res = solve(0,-1,0);
        printf("%lld\n",res);
    }
    return 0;
}
