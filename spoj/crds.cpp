#include <bits/stdc++.h>
#define mod 1000007
#define ll long long
using namespace std;
int main()
{
    int t;
    ll n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ll res = (2*n + (3*n*(n-1))/2)%mod;
        cout<<res<<endl;
    }
}
