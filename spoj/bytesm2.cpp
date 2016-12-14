#include <bits/stdc++.h>
using namespace std;
int dp[102][102];
int main()
{
    int t,i,j,n,m,a[102][102];
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(i=0;i<n;i++)for(j=0;j<m;j++)cin>>a[i][j];
        for(j=0;j<m;j++)dp[0][j]=a[0][j];
        for(i=1;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                dp[i][j] = dp[i-1][j];
                if(j-1>=0)dp[i][j] = max(dp[i][j],dp[i-1][j-1]);
                if(j+1<m)dp[i][j] = max(dp[i][j],dp[i-1][j+1]);
                dp[i][j]+=a[i][j];
                //cout<<dp[i][j]<<' ';
            }
            //cout<<endl;
        }
        int res=0;
        for(j=0;j<m;j++)res = max(res,dp[n-1][j]);
        cout<<res<<endl;

    }
    return 0;
}
