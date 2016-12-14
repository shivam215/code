#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,d;
ll dp[1<<16];
ll base(vector<ll> v)
{
    ll b=1;
    ll res=0;
    for(ll i=0;i<v.size();i++)
    {
        res = res + b*v[i];
        b = b*d;
    }
    return res;
}
ll xorr(vector<ll> v)
{
    ll sum = 0;
    ll xo = 0;
    for(ll i=0;i<v.size();i++)
    {
        sum = sum + v[i];
        xo = xo^v[i];
    }
    return sum*xo;
}
ll solve(vector<ll> v)
{
    ll temp = base(v);
    if(temp==0)return 0;
    ll &ret = dp[temp];
    if(ret!=-1)return ret;
    ll res = LLONG_MAX;
    for(ll i=0;i<v.size();i++)
    {
        if(v[i]-1>=0)
        {
            v[i] = v[i]-1;
            res = min(res,solve(v));
            v[i]=v[i]+1;
        }
    }
    ret = res + xorr(v);
    return ret;
}
int main()
{
    int t;
    cin>>t;
    vector<ll> v;
    while(t--)
    {
        cin>>n>>d;
        v.clear();
        for(ll i=0;i<n;i++)
        {
            v.push_back(d-1);
        }
        memset(dp,-1,sizeof(dp));
        cout<<solve(v)<<endl;
        //for(ll i=0;i<10;i++)cout<<dp[i]<<endl;
    }
    return 0;
}
