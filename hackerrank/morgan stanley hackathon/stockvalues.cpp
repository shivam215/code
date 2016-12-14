#include <bits/stdc++.h>
#define inf 1000000000000LL
#define mod 1000000007
#define scano(x) scanf("%d",&x)
#define scanll(x) scanf("%lld",&x)
#define scant(x,y) scanf("%d%d",&x,&y)
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fe first
#define se second
using namespace std;
int n;
ll rec(int i,vector<ll>& v)
{
    if(i==n-1)
    {
        ll ans=0;
        for(int i=0;i<(n/2);i++)
        {
            ans = ans + abs(v[i]-v[n-i-1]);
        }
        return ans;
    }
    ll res=0;
    vector<ll> vec =v;
    res = max(res,rec(i+1,vec));
    if(!(v[i-1]&1)&&!(v[i+1]&1))
    {
        v[i] = (v[i-1]+v[i+1])/2;
        res = max(res,rec(i+1,v));
    }
    return res;
}
int main()
{
    int t;
    vector<ll> v;
    cin>>t;
    while(t--)
    {
        scano(n);
        v.clear();
        rep(i,0,n)
        {
            ll temp;
            cin>>temp;
            v.pb(temp);
        }
        ll res = rec(1,v);
        printf("%lld\n",res);
    }
    return 0;
}
