#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll solve(ll n)
{
    ll res = 0;
    for(ll i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            res = res + i;
            if(i!=n/i)
            {
                res = res + n/i;
            }
        }
    }
    res = res+n+(n!=1);
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    ll n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        printf("%lld\n",solve(n));
    }
    return 0;
}
