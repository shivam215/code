#include <bits/stdc++.h>
#define ll long long
#define mod 100000007
using namespace std;
int dp[1030][1030],has[1030],a[1030],b[1030];
int main()
{
    int t,n,m;
    cin>>t;
    for(int test=1;test<=t;test++)
    {
        cin>>n>>m;
        memset(has,0,sizeof(has));
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<m;i++){cin>>b[i];has[b[i]]=1;}
        dp[0][0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<1030;j++)
            {
                int xo = j^a[i-1];
                dp[i][j] = (dp[i-1][j] + dp[i-1][xo])%mod;
            }
        }
        int res=0;
        for(int j=0;j<1030;j++)
        {
            if(!has[j])res = (res + dp[n][j])%mod;
        }
        printf("Case %d: %d\n",test,res);
    }
    return 0;
}
