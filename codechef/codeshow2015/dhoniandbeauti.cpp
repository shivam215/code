#include <bits/stdc++.h>
#define M 1000000007
#define ll long long
using namespace std;
ll fastexp(ll a, ll b)
{
    ll res=1;
    while(b>0)
    {
        if(b%2==1)res=(res*a)%M;
        b = b>>1;
        a = (a*a)%M;
    }
    return res;
}
int main()
{
    int t;
    ll n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ll tot = faxtexp(3LL,n);
        if(n==1||n==2){cout<<tot<<endl;continue;}
        ll tem = fastexp(3LL,n-3);


    }
}
