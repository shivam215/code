#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    ll n,k,a[1003],b[1003],x,c[1003],i,j;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(i=1;i<=n;i++)cin>>a[i];
        for(i=1;i<=n;i++)
        {
            cin>>x;
            b[x] = i;
        }
        //for(i=1;i<=n;i++)cout<<b[i]<<endl;
        if(k==0)for(i=1;i<=n;i++)cout<<a[i]<<' ';
        else
        {
            for(i=1;i<=k;i++)
            {
                if(i&1)
                {
                    for(j=1;j<=n;j++)c[j]=a[b[j]];
                }
                else
                {
                    for(j=1;j<=n;j++)a[j] = c[b[j]];
                }
            }
            if(i&1)for(j=1;j<=n;j++)cout<<a[j]<<' ';
            else for(j=1;j<=n;j++)cout<<c[j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}
