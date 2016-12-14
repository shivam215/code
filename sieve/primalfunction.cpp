#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll prime[100005];
void sieve()
{
    ll i,j;
    for(i=1;i<100005;i++)prime[i]=1;
    for(i=2;i<100005;i++)
    {
        if(prime[i]==1)
        {for(j=1;j*i<100005;j++)
        {
            prime[i*j]*=i;
        }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    int q;
    ll i,n,k,j;
    cin>>q;
    vector< pair<ll,ll> > a;
    sieve();
    for(i=1;i<100001;i++)
    {
        a.push_back(make_pair(prime[i],i));
    }
    sort(a.begin(),a.end());
    while(q--)
    {
        cin>>n>>k;
        ll cnt=0;
        for(i=0;i<100001;i++)
        {
           if(a[i].second<=n)cnt++;
           if(cnt==k)break;
        }
        printf("%lld\n",a[i].second);
    }
    return 0;
}
