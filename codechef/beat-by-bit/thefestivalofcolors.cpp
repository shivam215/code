#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[65];
ll fib(ll n)
{
    if(n==1)return 2LL;
    if(n==2)return 3LL;
    if(a[n])return a[n];
    ll temp1 = fib(n-1);
    ll temp2 = fib(n-2);
    a[n] = temp1 + temp2;
    return a[n];
}
int main()
{
    ios_base::sync_with_stdio(false);
    int q;
    ll n;
    cin>>q;
    a[1]=2LL;a[2]=3LL;
    while(q--)
    {
        cin>>n;
        cout<<fib(n)<<endl;
    }
    return 0;
}
