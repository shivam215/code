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
ll sum1,sum2;
int x[200005],y[200005];
bool comp(int a,int b)
{
    return a>b;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    rep(i,1,n+1)
    {
        cin>>x[i]>>y[i];
        sum1 = (sum1 + x[i])%mod;
        sum2 = (sum2 + y[i])%mod;
    }
    sort(x+1,x+n+1,comp);
    sort(y+1,y+n+1,comp);
    ll res=0;
    rep(i,1,n+1)
    {
        sum1 = (sum1-x[i]+mod)%mod;
        sum2 = (sum2 - y[i]+mod)%mod;
        res = (res + 1LL*(n-i)*x[i] - sum1 + 1LL*(n-i)*y[i] - sum2)%mod;
        res = (res+mod)%mod;
    }
    printf("%lld\n",res);
    return 0;
}
