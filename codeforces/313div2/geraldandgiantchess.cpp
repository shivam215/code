#include <bits/stdc++.h>
#define mod 1000000007
#define MAX 200005
#define ll long long
using namespace std;
ll f[2003],fac[MAX],invfac[MAX];
typedef pair<ll,ll> ii;
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
ll C(ll n, ll r)
{
    if(n<r)return 0;
    ll a = fac[n];
    ll b = invfac[r];
    ll c = invfac[n-r];
    ll res = (a*((b*c)%mod))%mod;
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    ll h,w,n,x,y,i,j;
    vector< ii > vec;
    cin>>h>>w>>n;
    for(i=0;i<n;i++)
    {
        cin>>x>>y;
        vec.push_back(ii(x,y));
    }
    vec.push_back(ii(h,w));
    sort(vec.begin(),vec.end());
    fac[0]=1;invfac[0]=1;
    for(i=1;i<MAX;i++)
    {
        fac[i] = (fac[i-1]*i)%mod;
        invfac[i] = (invfac[i-1]*fastexp(i,mod-2))%mod;
    }
    for(i=0;i<=n;i++)
    {
        x = vec[i].first;
        y = vec[i].second;
        f[i] = C(x+y-2,x-1);
        for(j=0;j<i;j++)
        {
            f[i] = ((f[i] - f[j]*(C(x-vec[j].first+y-vec[j].second,x-vec[j].first)))%mod + mod)%mod;
        }
    }
    printf("%lld\n",f[n]);
    return 0;
}
