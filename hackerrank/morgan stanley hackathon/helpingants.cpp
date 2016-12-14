#include <bits/stdc++.h>
#define inf 1000000000
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
ll fast(ll a, ll b)
{
    ll res=1;
    while(b>0)
    {
        if(b&1)res=(res*a)%mod;
        a = (a*a)%mod;
        b>>=1;
    }
    return res;
}
ll f(ll n)
{
    if(n==1)return 1;
    if(n==2)return 6;
    ll res = (2*fast(3,n-1) + ((fast(3,n-2)-1+mod)%mod)*fast(2,mod-2))%mod;
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll total = f(n);
        ll des = fast(2,n-1);
        ll res = ((total-des)%mod + mod)%mod;
        printf("%lld\n",res);
    }
    return 0;
}
