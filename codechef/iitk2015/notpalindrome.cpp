#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t;
    ll n,m;
    cin>>t;
    map<int,ll> f;
    f[1]=1;
    for(ll i=2;i<=1000000;i++)
    {
        f[i] = (f[i-1]*i)%mod;
    }
    while(t--)
    {
        cin>>n>>m;
        if(m<n)
            cout<<"0"<<endl;
        else
        {
            if(m<=1000000)
            {
                if(m==n)
                    cout<<f[m]<<endl;
                else
                    cout<<f[m]/f[m-n]<<endl;
            }
            else
            {
                ll res;
                if(m==n)
                {
                    res = f[1000000];
                    for(ll i=1000001;i<=m;i++)
                        res = (res*i)%mod;
                }
                else
                {
                    res = 1;
                    for(ll i=m-n+1;i<=m;i++)
                        res = (res*i)%mod;

                }
                cout<<res<<endl;
            }
        }
    }
    return(0);
}
