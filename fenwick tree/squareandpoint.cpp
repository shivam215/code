#include <bits/stdc++.h>
#define scanint(x) scanf("%d",&x)
#define scanll(x) scanf("%lld",&x)
#define pb push_back
#define mp make_pair
#define ll long long
#define pll pair<ll,ll>
#define plll pair< ll,pll >
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
ll t[300010];
map<ll,ll> ma;
pll p[100005],q[100005];
ll a[300010];
plll b[300010];
int k;
bool comp(plll x, plll y)
{
   return x.first!=y.first?x.first<y.first:x.second.first<y.second.first;
}
void upd(int i, int x)
{
    for (; i <= k; i += i & -i) t[i] += x;
}

ll get(int i)
{
    ll s = 0;
    for (; i; i -= i & -i) s += t[i];
    return s;
}
int main()
{
    int n,m;
    ll l;
    cin>>n>>m>>l;
    int d=0,x=0;
    for(int i=0;i<n;i++)
    {
        cin>>p[i].first>>p[i].second;

        a[d++]=p[i].second;
        a[d++] = p[i].second+l+1;

        b[x].first = p[i].first;
        b[x].second.first = 0;
        b[x++].second.second = p[i].second;

        b[x].first = p[i].first+l;
        b[x].second.first = 2;
        b[x++].second.second = p[i].second;
    }
    for(int i=0;i<m;i++)
    {
        cin>>q[i].first>>q[i].second;
        a[d++]=q[i].second;

        b[x].first = q[i].first;
        b[x].second.first = 1;
        b[x++].second.second = q[i].second;
    }
    sort(a,a+d);
    sort(b,b+x,comp);
    /*for(int i=0;i<x;i++)
    {
        cout<<b[i].first<<' '<<b[i].second.first<<' '<<b[i].second.second<<endl;
    }*/
    ma[a[0]]=k=1;
    for(int i=1;i<d;i++)ma[a[i]] = a[i]!=a[i-1]?++k:k;
    ll res=0;
    for(int i=0;i<x;i++)
    {
        ll e = b[i].first;
        ll f = b[i].second.first;
        ll g = b[i].second.second;
        if(f==0)
        {
            upd(ma[g],1);
            upd(ma[g+l+1],-1);
        }
        else if(f==1)
        {
            res = max(res,get(ma[g]));
        }
        else if(f==2)
        {
            upd(ma[g],-1);
            upd(ma[g+l+1],1);
        }
    }
    cout<<res<<endl;
    return 0;
}
