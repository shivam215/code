#include <bits/stdc++.h>
using namespace std;
int dp[4][100];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    dp[0][0]=1;
    dp[1][0]=0;
    dp[2][0]=1;
    dp[3][0]=0;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(a[i]>=a[j]])
            {
                dp[0][i] = max(dp[0][i],1+dp[0][j]);
                dp[3][i] = max(dp[3][i],max(dp[3][j],dp[2][j])+1);
            }
            else
            {
                dp[2][i] = max(dp[2][i],1+dp[2][j]);
                dp[1][i] = max(dp[1][i],max(dp[1][j],dp[2][j])+1);
            }
        }
    }

}
