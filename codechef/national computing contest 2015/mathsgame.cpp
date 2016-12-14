#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll k;
ll fastexp(ll a, ll b)
{
    ll res=1;
    while(b>0)
    {
        if(b&1)res=(res*a)%k;
        a = (a*a)%k;
        b>>=1;
    }
    return res;
}
int main()
{
    int t;
    ll i,a,b;
    string n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        cin>>k;
        a=0;
        for(i=0;i<n.size();i++)
        {
            a = (a*10 + n[i]-'0')%k;
        }
        b=1;
        for(i=0;i<m.size();i++)
        {
            b = fastexp(b,10);
            b = (b*fastexp(a,(ll)m[i]-'0'))%k;
        }
        cout<<b<<endl;
    }
    return 0;
}
