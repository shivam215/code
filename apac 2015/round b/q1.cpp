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
ll fac[105],invfac[105];
ll fastexp(ll a, ll b)
{
    ll res=1;
    while(b>0)
    {
        if(b&1)res=(res*a)%mod;
        a = (a*a)%mod;
        b>>=1;
    }
    return res;
}
ll comb(ll n, ll r)
{
    if(n<r)return 0;
    if(n==r||r==0)return 1;
    ll a = (fac[n]*invfac[n-r])%mod;
    a = (a*invfac[r])%mod;
    return a;
}
int main()
{
    //freopen("q1s.in","r",stdin);
    //freopen("q1s.out","w",stdout);
    int t;
    cin>>t;
    fac[0]=1;invfac[0]=1;
    for(int i=1;i<105;i++)
    {
        fac[i] = (fac[i-1]*i)%mod;
        invfac[i] = (invfac[i-1]*fastexp(i,mod-2))%mod;
    }
    rep(test,1,t+1)
    {
        scant(m,n);
        ll res=0;
        for(int i=0;i<m;i++)
        {
            if(i&1)
            {
                res =((res - comb(m,i)*fastexp(m-i,n))%mod + mod)%mod;
            }
            else
            {
                res = (res + comb(m,i)*fastexp(m-i,n))%mod;
            }
        }
        printf("Case #%d: %lld\n",test,res);
    }
    return 0;
}
