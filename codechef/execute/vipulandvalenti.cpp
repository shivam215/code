#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
#define p(x) pair<x,x>
using namespace std;
int x,y,z,a,b,c,d,e,f;
map<pair<pair<int,int>,int>,ll> m;
long long func(int p,int q, int r)
{
    if(p>x || q>y || r>z)
        return 0;
    if(p==a&&q==b&&r==c)return 0;
    if(p==d&&q==e&&r==f)return 0;
    if(p==x && q==y && r==z)return 1;
    int d1=x-p,d2=y-q,d3=z-r;
    if(m[make_pair(make_pair(d1,d2),d3)])return m[make_pair(make_pair(d1,d2),d3)];
    ll s = ((func(p+1,q,r))%mod+(func(p,q+1,r))%mod+(func(p,q,r+1))%mod)%mod;
    m[make_pair(make_pair(d1,d2),d3)] = s;
    /*m[make_pair(make_pair(d1,d3),d2)] = s;
    m[make_pair(make_pair(d2,d1),d3)] = s;
    m[make_pair(make_pair(d2,d3),d1)] = s;
    m[make_pair(make_pair(d3,d1),d2)] = s;
    m[make_pair(make_pair(d3,d2),d1)] = s;*/
    return s;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>x>>y>>z;
        cin>>a>>b>>c;
        cin>>d>>e>>f;
        m.clear();
        cout<<func(0,0,0)<<endl;
    }
    return 0;
}
