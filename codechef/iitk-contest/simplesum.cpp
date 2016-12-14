#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll mul(ll a, ll b, ll mod)
{
   	ll res = 0;
    while (b)
    {
        if (b & 1)
		{
			res = (res + a);
			res %= mod;
		}
        a = (a + a);
		a %= mod;
		b >>= 1;
    }
    return res;
}
ll fastexp(ll a, ll b){ll x=1,y=a;while(b>0){if(b&1)x=x*y;y=y*y;b>>=1;}return x;}
ll fastexpmod(ll a, ll b, ll c){ll x=1,y=a;while(b>0){if(b&1)x=mul(x,y,c);y=mul(y,y,c);b>>=1;}return x%c;}
ll getsum(ll x, ll m, ll n)
{
    x = x%n;
    if(m==0)return 1LL%n;
    if(m==1)return (1+x)%n;
    if(m&1)
    {
        ll tem = getsum(mul(x,x,n),m/2,n);
        tem = mul(tem,1+x,n);
        return tem;

    }
    else
    {
        ll temp = getsum(x,m-1,n);
        temp = mul(temp,x,n);
        temp+=1;
        temp%=n;
        return temp;
    }
}
int main()
{   ios_base::sync_with_stdio(false);
    ll x,m,n,res;
    int T;
    cin>>T;
    while(T--)
    {
        cin>>x>>m>>n;
        res = getsum(x,m,n);
        cout<<res<<endl;
    }
    return(0);
}
