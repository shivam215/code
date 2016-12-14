#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
ll gcd(ll a, ll b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    ll n,res;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ll p = n*(n-1);
        p = p/2;
        ll q = 2*n-1;
        if(p%3==0)p=p/3;
        else q = q/3;
        res = ((p%mod)*(q%mod))%mod;
        for(ll i=1;i<n;i++)
        {
            if(gcd(n,i)!=1){res = (res-((i*i)%mod))%mod;}
        }
        res = (res+mod)%mod;
        cout<<res<<endl;
    }
    return 0;
}
