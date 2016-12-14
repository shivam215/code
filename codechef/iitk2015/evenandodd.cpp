#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    long long e,o,cnt1,cnt2,ans;
    cin>>t;
    while(t--)
    {
        cin>>e>>o;
        long long m=e;
        long long n=o;
        cnt1=0;
        cnt2=0;
        while(e%2!=0 || o%3!=0)
        {
            e = e-1;
            o = o+1;
            cnt1++;
        }
        while(m%2!=0 || n%3!=0)
        {
            m = m+1;
            n = n-1;
            cnt2++;
        }
        //cout<<e<<o<<m<<n;
        e = e/2;
        o = o/3;
        m = m/2;
        n = n/3;
        ans=-1;
        if(e-o>=0)
        {
            if((e-o)%5==0)
                ans = cnt1 + ((e-o)/5)*6;
        }
        if((n-m)>=0)
        {
            if((n-m)%5==0)
            {
                if(ans>=0)
                    ans = min(ans,cnt2+((n-m)/5)*6);
                else
                    ans = cnt2 + (((n-m)/5)*6);
            }
        }
        cout<<ans<<endl;

    }
    return(0);
}
