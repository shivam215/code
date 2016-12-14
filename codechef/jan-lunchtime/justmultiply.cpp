#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;
ll m;
ll multiply(ll a, ll b)
{
    ll res=0;
    while(b)
    {
        if(b%2!=0)res=(res+a)%m;
        b=b/2;
        a = (a+a)%m;
    }
    return res%m;
}
ll fastexp(ll a,ll b)
{
    ll res=1;
    while(b>0)
    {
        if(b%2==1)res=multiply(res,a);
        b=b>>1;
        a=multiply(a,a);
    }
    return res%m;
}
int main()
{
    int t;
    string s;
    ll res,temp,a,b,i;
    cin>>t;
    while(t--)
    {
        cin>>m;
        cin>>s;
        i=0;res=1;
        while(s[i]!='\0')
        {
            temp=10;a=0;
            while(s[i]!='*')
            {
                a = (multiply(a,temp)+s[i]-'0')%m;
                i++;
            }
            i=i+2;
            ll xy=1;
            while(s[i]!='*' && s[i]!='\0')
            {
                ll exp=s[i]-'0';
                xy = fastexp(xy,10);
                xy = multiply(xy,fastexp(a,exp));
                i++;
            }
            res = multiply(res,xy);
            if(s[i]=='\0')
                break;
            i++;
        }
        cout<<res%m<<endl;
    }
    return 0;
}
