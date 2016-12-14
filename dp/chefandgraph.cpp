#include <bits/stdc++.h>
#include <map>
#define mod 1000000007
#define ll unsigned long long
#define multi(ll) multimap< pair<ll,ll>,pair<ll,ll> >
using namespace std;
ll fastexp(ll a, ll b)
{
    ll res=1;
    a = (a%mod);
    while(b>0)
    {
        if(b&1)res=(res*a)%mod;
        a = (a*a)%mod;
        b = b>>1;
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    ll n,m,k,a,b,c,d,i,j;
    cin>>n>>m>>k;
    vector< pair<ll,ll> > v;
    multi(ll) mp;
    map<pair<ll,ll>,ll> pt;
    map<ll,ll> layer;

    for(i=0;i<k;i++)
    {
        cin>>a>>b>>c>>d;
        v.push_back(make_pair(a,b));
        v.push_back(make_pair(c,d));
        mp.insert(make_pair(make_pair(c,d),make_pair(a,b)));
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    //for(i=0;i<v.size();i++)cout<<v[i].first<<' '<<v[i].second<<endl;
    layer[0]=1;
    pt[make_pair(0,0)]=1;
    ll temp=0;
    for(i=0;i<v.size();i++)
    {
        a = v[i].first;
        b = v[i].second;
        if(a==0)continue;
        if(a!=n+1)layer[a] = (layer[temp]*fastexp(m,a-temp))%mod;
        else layer[a] = (layer[temp]*fastexp(m,a-temp-1))%mod;
        pair<multi(ll)::iterator,multi(ll)::iterator> ret;
        ret = mp.equal_range(make_pair(a,b));
        multi(ll)::iterator it;
        for(it=ret.first;it!=ret.second;++it)
        {
            c = (it->second).first;
            d = (it->second).second;
            pt[make_pair(a,b)] = (pt[make_pair(a,b)] + pt[make_pair(c,d)])%mod;
        }
        layer[a] = (layer[a] + pt[make_pair(a,b)])%mod;
        if(layer[a-1]==0)layer[a-1] = (layer[temp]*fastexp(m,a-1-temp))%mod;
        pt[make_pair(a,b)] = (pt[make_pair(a,b)]+layer[a-1])%mod;
        temp=a;
        //cout<<pt[make_pair(a,b)]<<endl;
    }
    if(temp!=n+1)layer[n+1] = (layer[temp]*fastexp(m,n-temp))%mod;
    //for(i=0;i<=n+1;i++)cout<<layer[i]<<endl;
    cout<<layer[n+1]<<endl;
    return 0;

}
