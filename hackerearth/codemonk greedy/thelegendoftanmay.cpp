#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll t,n,a[20],cnt;
    ll mn,mx;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cnt=0;
        for(int i=0;i<n;i++){cin>>a[i];if(a[i]!=0)cnt++;}
        if(cnt==0||cnt==1)
        {
            mn=a[0];mx=a[0];
            for(int i=1;i<n;i++)
            {
                mn = min(mn,a[i]);
                mx = max(mx,a[i]);
            }
            cout<<mx<<' '<<mn<<endl;
            continue;
        }
        sort(a,a+n);
        mx=1;
        ll negmax=INT_MIN;
        for(int i=n-1;i>=0;i--)
        {
            if(a[i]!=0)mx=mx*a[i];
            if(a[i]<0)negmax = max(negmax,a[i]);
        }
        mn=INT_MAX;
        if(a[0]>=0)
        {
            for(int i=0;i<n;i++)
            {mn=min(mn,a[i]);

            }
        }
        else
        {
            if(mx<0){mn=mx;mx=mx/negmax;}
            else
            {
                mn = mx/negmax;
            }
        }
        cout<<mx<<' '<<mn<<endl;
    }
    return 0;
}
