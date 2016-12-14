#include <bits/stdc++.h>
#define mod 1000003
#define ll long long
using namespace std;
//ll fact[1000005],ifact[1000005];
ll fastexp(ll a, ll b)
{
    ll res =1;
    while(b>0)
    {
        if(b&1)res=(res*a)%mod;
        a = (a*a)%mod;
        b>>=1;
    }
    return res;
}
void basemod(ll n, ll *a)
{
    ll i=0;
   while(n>0)
   {
       a[i] = (n%mod);
       n = (n/mod);
       i++;
   }
}
ll comb(ll n, ll r)
{
    ll i,res=1,inv=1;
    for(i=1;i<=r;i++)
    {
        res = (res*(n-r+i))%mod;
    }
    for(i=1;i<=r;i++)
    {
        inv = (inv*i)%mod;
    }
    inv = fastexp(inv,mod-2);
    res = (res*inv)%mod;
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    ll n,l,r,m,fac,i;
    cin>>t;
    //fact[0]=1;ifact[0]=1;
    /*for(i=1;i<1000005;i++)
    {
        fact[i] = (i*fact[i-1])%mod;
        ifact[i] = (fastexp(i,mod-2)*ifact[i-1])%mod;
    }*/
    while(t--)
    {
        cin>>m>>l>>r;
        ll a[2]={0},b[2]={0};
        n = r-l;
        basemod(n+m+1,a);
        basemod(m,b);
        //cout<<a[0]<<' '<<b[0]<<endl;
        //cout<<a[1]<<' '<<b[1]<<endl;
        ll p,q;
        if(a[0]<b[0])p=0;
        else p = comb(a[0],b[0]);
        //else p = (((fact[a[0]]*ifact[a[0]-b[0]])%mod)*ifact[b[0]])%mod;
        if(a[1]<b[1])q=0;
        else q = comb(a[1],b[1]);
        //else q = (((fact[a[1]]*ifact[a[1]-b[1]])%mod)*ifact[b[1]])%mod;
        //cout<<p<<' '<<q<<endl;
        ll res = (p*q)%mod;
        res = (res-1+mod)%mod;
        printf("%lld\n",res);
    }
    return 0;
}
