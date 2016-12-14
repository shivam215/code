#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    ll n,k,i;
    ll a[100005];
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        ll tem=0;
        for(i=1;i<n;i++)
        {
            if(k>tem && k<=tem+n-i)
            {
                break;
            }
            tem = tem+n-i;
        }
        //cout<<i<<endl;
        ll f=i;
        ll l=i+k-tem;
        sort(a,a+n);
        cout<<a[f]+a[l]<<endl;
    }
    return 0;
}
