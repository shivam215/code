#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
int main()
{
    int t,i;
    long long n,sum;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n&1)
        {
            for(i=0;i<=n/2;i++)
            {
                sum = sum + 2*fac(n,i);
            }
        }
        else
        {
            for(i=0;i<n/2;i++)
            {
                sum = sum + 2*fac(n,i);
            }
            sum = sum + fac(n,n/2);
        }
        cout<<sum<<endl;
    }
}
