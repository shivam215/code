#include <bits/stdc++.h>
#define inf 100000000
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
int n,m;
ll dp[10000007];
ll fastexp(ll a,ll b)
{
    if(a==1)return 1;
    ll res=1;
    while(b>0)
    {
        if(b&1)
        {
            res = (res*a);
            if(res>=mod)res%=mod;
        }
        a = (a*a);
        if(a>=mod)a%=mod;
        b>>=1;
    }
    return res;
}
ll rec(ll x)
{
    int a = m/x;
    if(a==1)return 1;
    if(dp[x]!=-1)return dp[x];
    ll tot = fastexp(a,n);
    int k = 2*x;
    ll sum=0;
    while(k<=m)
    {
        sum = (sum + rec(k));
        if(sum>=mod)sum%=mod;
        k+=x;
    }
    ll ans = (tot-sum);
    if(ans<0)ans+=mod;
    if(ans>=mod)ans%=mod;

    return dp[x]=ans;
}
int main()
{
    int t;
    scano(t);
    while(t--)
    {
        int l,r;
        scant(n,m);
        scant(l,r);
        ll sum = 0;
        memset(dp,-1,sizeof(dp));
        for(int i=l;i<=r;i++){sum = sum + rec(i);if(sum>=mod)sum%=mod;}
        printf("%lld\n",sum);
    }
    return 0;
}
