#include <bits/stdc++.h>
using namespace std;
int dp[2003][2003];
int main()
{
    int t;
    string a,b;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        int n = a.size();
        int m = b.size();
        memset(dp,0,sizeof(dp));
        for(int i=0;i<m;i++)dp[i][0] = i;
        for(int i=0;i<n;i++)dp[0][i]=i;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                dp[i][j] = min(min(dp[i-1][j],dp[i][j-1])+1,dp[i-1][j-1]+(a[i-1]!=b[j-1]));
            }
        }
        int res = dp[n][m];
        cout<<res<<endl;
    }
    return 0;
}
