#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    ll d,i,l,n,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>k>>l;
        ll a[n];
        for(i=0;i<n;i++)a[i]=1;
        d = l-1;i=n-1;
        while(d)
        {
            a[i] = (d%k + 1);
            d = d/k;
            i = i-1;
        }
        for(i=0;i<n;i++)cout<<a[i]<<' ';
        cout<<endl;
    }
    return 0;
}
