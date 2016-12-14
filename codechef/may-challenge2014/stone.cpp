#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n,k,i;
    ll a[100005];
    cin>>n>>k;
    for(i=0;i<n;i++)
        cin>>a[i];
    if(k==0)
    {
        for(i=0;i<n;i++)
        {cout<<a[i]<<' ';
        }
        return 0;
    }
    ll mx,mn;
    mx=a[0];mn=a[0];
    for(i=1;i<n;i++)
    {
        if(a[i]>mx)mx=a[i];
        if(a[i]<mn)mn=a[i];
    }
    k = k%2;
    if(k==1)
    {
        for(i=0;i<n;i++)
        {
            cout<<mx-a[i]<<' ';
        }
        return 0;
    }
    else
    {
        for(i=0;i<n;i++)
        {
            cout<<a[i]-mn<<' ';
        }
        return 0;
    }
    return 0;
}
