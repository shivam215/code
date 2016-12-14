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
ll fastexp(ll a,ll b)
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
int main()
{
    int n;
    cin>>n;
    ll res = ((fastexp(3,3*n) - fastexp(7,n))%mod+mod)%mod;
    cout<<res<<endl;
    return 0;
}
