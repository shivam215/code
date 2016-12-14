#include <bits/stdc++.h>
#define scanll(x) scanf("%d",&x)
#define scanll(x) scanf("%lld",&x)
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector<ll>
#define pii pair<ll,ll>
#define vpii vector< pii >
#define rep(i,a,b) for(ll i=a;i<b;i++)
using namespace std;
ll prime[1000005];
ll ans[1000005];
void sieve()
{
    for(ll i=2;i<1000005;i++)prime[i]=1;
    for(ll i=2;i*i<1000005;i++)
    {
        if(prime[i]==1)
        {
            for(ll j=i*i;j<1000005;j+=i)
            {
                prime[j]=0;
            }
        }
    }
}
int main()
{
    ll t;
    cin>>t;
    sieve();
    while(t--)
    {
        ll n,m;
        cin>>m>>n;
        for(ll i=1;i<1000005;i++)ans[i]=1;
        if(n<1000005)
        {
            for(ll i=m;i<=n;i++)
            {
                if(prime[i])printf("%lld\n",i);
            }
            continue;
        }
        for(ll i=2;i*i<=n;i++)
        {
            if(prime[i]==1)
            {
                ll s = m/i;
                s = s*i;
                for(ll j=s;j<=n;j+=i)
                {
                    if(j>=m)ans[j-m+1]=0;
                }
            }
        }
        for(ll i=m;i<=n;i++)
        {
            if(ans[i-m+1]==1)
            {
                printf("%lld\n",i);
            }
        }
    }
    return 0;
}
