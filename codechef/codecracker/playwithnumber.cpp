#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    ll n,k,a,res=0;
    cin>>n>>k;
    map<ll,ll> m;
    while(n--)
    {
        cin>>a;
        if(!m[a])
        {
        if((a<k)&&(a&1)){res++;}
        m[a]=1;
        }
    }
    cout<<res<<endl;
    return 0;
}
