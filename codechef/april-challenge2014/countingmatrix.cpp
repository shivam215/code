#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    ll t,n,temp,res,i,totalfac,j;
    cin>>t;
    while(t--)
    {
        cin>>n;
        res=0;
        for(i=1;i<=n/2;i++)
        {
            temp = i*(n-i)-1;
            totalfac=0;
            for(j=1;j*j<=temp;j++)
            {
                if(j==1)totalfac+=2*(temp-1)+1;
                else totalfac+=(temp/j-j)*2+1;
            }
            if(i!=n-i)totalfac*=2;
            res+=totalfac;
        }
        printf("%lld\n",res);
    }
    return 0;
}
