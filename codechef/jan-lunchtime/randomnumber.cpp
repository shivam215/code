#include <bits/stdc++.h>
#define mod 104857601
#define ll long long
#define map(ll) map< pair<ll,ll>,ll >
using namespace std;
ll n,k;
ll a[100005],c[100005];
map(ll) mp;
map(ll) multiplication(map(ll) a,map(ll) b)
{
   map(ll) c;
   for(ll i=1;i<=k;i++)
   {
       for(ll j=1;j<=k;j++)
       {
           for(ll l=1;l<=k;l++)
           {
               c[make_pair(i,j)] = (c[make_pair(i,j)]+(a[make_pair(i,l)]%mod)*(b[make_pair(l,j)]%mod))%mod;
           }
       }
   }
   return c;
}
map(ll) power(map(ll) m, ll c)
{
    if(c==1)return m;
    map(ll) f = m;
    map(ll) f1 = power(m,c/2);
    map(ll) f2 = multiplication(f1,f1);
    map(ll) f3;
    if(c%2==1)f3 = multiplication(f2,f);
    else f3 = f2;
    return f3;
}
int main()
{
    ios_base::sync_with_stdio(false);
    ll i,j;
    cin>>k>>n;
    for(i=1;i<=k;i++)cin>>a[i];
    for(i=1;i<=k;i++)cin>>c[i];
    if(n==k)
    {
        cout<<a[n]%mod<<endl;
        return 0;
    }
    for(i=1;i<=k;i++)
    {
        for(j=1;j<=k;j++)
        {
            if(i==1)mp[make_pair(i,j)] = c[j];
            else
            {
                if(i==j+1)mp[make_pair(i,j)]=1;
                else mp[make_pair(i,j)]=0;
            }
        }
    }
    mp = power(mp,n-k);
    //for(i=1;i<=k;i++)for(j=1;j<=k;j++)cout<<mp1[make_pair(i,j)]<<endl;
    ll res=0;
    for(j=1;j<=k;j++)
    {
        res = (res + (mp[make_pair(1,j)]%mod)*(a[k-j+1]%mod))%mod;
    }
    cout<<res<<endl;
    return 0;
}
