#include <bits/stdc++.h>
#define mod 10000007
using namespace std;
int main()
{
    int n,m,i,j;
    cin>>n>>m;
    int a[n][m];
    long long col[40]={0};
    long long res=1;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            col[i] = (col[i]+a[j][i]+mod)%mod;
        }
    }
    for(i=0;i<m;i++)
    {
        res = ((res*col[i])+mod)%mod;
    }
    cout<<res<<endl;
    return(0);
}
