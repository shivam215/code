#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    ll s,c,k,i,j,p,res;
    long long a[200];
    cin>>t;
    while(t--)
    {
        memset(a,0,sizeof(a));
        cin>>s>>c>>k;
        for(i=1;i<=s;i++)
        {
            if(i<s)
            {
                a[i] = 1LL<<(s-i);
            }
            else a[i]=3;
        }
        p=c;
        for(j=s-1;j>=1;j--)
        {
            if(p>0)
            {
                a[j+1] = a[j+1]+a[j];
                a[j]=0;
                p--;
            }
        }
        while(p>0)
        {
            a[1] = a[1] + (1LL<<(c-p+1));
            p--;
        }
        res=0;
        for(i=k;i<=s+c;i++)
        {
            res = res + a[i];
        }
        cout<<res<<endl;
    }
    return 0;
}
