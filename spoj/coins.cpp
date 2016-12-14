#include <bits/stdc++.h>
#define ll long long
using namespace std;
map<ll,ll> mp;
ll recur(ll n)
{
    if(mp[n])return mp[n];
    if(n==0)return 0;
    ll res = max(n,recur(n/2)+recur(n/3)+recur(n/4));
    mp[n]=res;
    return res;
}
int main()
{
    int t=10;
    ll n;
    while(t--)
    {
        cin>>n;
        cout<<recur(n)<<endl;
    }
    return 0;
}
