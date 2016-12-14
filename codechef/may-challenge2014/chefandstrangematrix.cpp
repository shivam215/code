#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    ll n,m,p,i;
    cin>>n>>m>>p;
    map<pair<ll,ll>,ll> mp;
    ll a[p+1],b[p+1];
    mp.clear();
    for(i=1;i<=p;i++)
    {
        cin>>a[i]>>b[i];
        mp[make_pair(a[i],b[i])]++;
    }
    ll c[n+1];
    for(i=1;i<=p;i++)
    {
        if(b[i]+1<=m)
        {
        if(mp[make_pair(a[i],b[i])]>mp[make_pair(a[i],b[i]+1)]+1)
        {
            c[a[i]] = -1;
        }
        }
    }
    for(i=1;i<=n;i++)
    {
        if(c[i]!=-1)
        {
            c[i]=m+mp[make_pair(i,m)]-1-mp[make_pair(i,1)];
        }
        cout<<c[i]<<endl;
    }
    return 0;
}
