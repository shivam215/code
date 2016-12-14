#include <bits/stdc++.h>
#define inf INT_MAX
using namespace std;
int a[1003],b[1003],sum1[1003],sum2[1003];
int dp[1003][1003];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        sum1[0]=0;sum2[0]=0;
        for(int i=1;i<n;i++){cin>>a[i];sum1[i]=sum1[i-1]+a[i];}
        for(int i=1;i<m;i++){cin>>b[i];sum2[i]=sum2[i-1]+b[i];}
        for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)dp[i][j]=inf;
        dp[1][1]=0;
        for(int i=2;i<=n;i++)dp[i][1]=sum1[i-1];
        for(int i=2;i<=m;i++)dp[1][i] = sum2[i-1];
        for(int i=2;i<=n;i++)
        {
            for(int j=2;j<=m;j++)
            {
                for(int cut=1;cut<i;cut++)
                {
                    dp[i][j] = min(dp[i][j],a[cut]+dp[cut][j]+dp[i-cut][j]);
                }
                for(int cut=1;cut<j;cut++)
                {
                    dp[i][j] = min(dp[i][j],b[cut]+dp[i][cut]+dp[i][j-cut]);
                }
            }
        }
        cout<<dp[n][m]<<endl;
    }
    return 0;
}
