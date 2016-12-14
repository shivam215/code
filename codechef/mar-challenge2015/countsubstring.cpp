#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    ll n,k,q,l,r,i,j,zero,one,k1,k2,km,kr,ans;
    ll a[100005],b[100005];
    string s;
    cin>>t;
    while(t--)
    {
        cin>>n>>k>>q;
        cin>>s;
        j=0;zero=0;one=0;
        //if(s[0]=='0')zero++;
        //else one++;
        for(i=0;i<n;i++)
        {
            while(zero<=k&&one<=k&&j<n)
            {
                if(s[j]=='0')zero++;
                else one++;
                if(zero>k||one>k)
                {
                    if(s[j]=='0')zero--;
                    else one--;
                    break;
                }
                j++;
            }
            a[i]=j-1;
            if(s[i]=='0')zero--;
            else one--;
            //cout<<a[i]<<endl;
        }
        b[0]=a[0];
        for(i=1;i<n;i++)
        {
             b[i] = b[i-1]+a[i];
        }
        while(q--)
        {
            cin>>l>>r;
            l--;r--;
            k1=l-1;k2=r+1;
            while(k2-k1>1)
            {
                km = (k1+k2)/2;
                if(a[km]<=r)k1=km;
                else k2=km;
            }
            kr=k1;
            ans = b[kr]-((l-1>=0)?b[l-1]:0)+ (r*(r-kr)) - (r*(r+1))/2 + (l*(l-1))/2 + (r-l+1);
            cout<<ans<<endl;
        }
    }
    return 0;
}
