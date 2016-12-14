#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t;
    ll x,b,p,q,r,c,res,i;
    vector< pair<ll,pair<ll,ll> > > v;
    cin>>t;
    while(t--)
    {
        cin>>x>>b;
        v.clear();
        while(b--)
        {
            cin>>p>>q;
            v.push_back(make_pair(p,make_pair(0,q)));
        }
        cin>>c;
        while(c--)
        {
            cin>>p>>q>>r;
            v.push_back(make_pair(p,make_pair(q,r)));
        }
        sort(v.begin(),v.end());
        res = 1;
        for(i=v.size()-1;i>=0;i--)
        {
            p = v[i].first;
            q = v[i].second.first;
            r = v[i].second.second;
            if(q==0)res = res+r;
            else
            {
                res = res-r;
                if(res<q)res=q;
            }
        }
        printf("%lld\n",res);
    }
    return 0;
}
