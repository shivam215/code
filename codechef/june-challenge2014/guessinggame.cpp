#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll gcd(ll x, ll y)
{
    if(y==0)
        return x;
    return gcd(y,x%y);
}

int main()
{
    long long t,n,m,u,l,g;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        u = ((n/2)*((m+1)/2)) + (((n+1)/2)*(m/2));
        l = n*m;
        g = gcd(u,l);
        cout<<u/g<<"/"<<l/g<<endl;
    }
    return 0;
}
