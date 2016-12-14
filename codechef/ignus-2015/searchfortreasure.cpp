#include <bits/stdc++.h>
using namespace std;
int dp[100005],a[100005],n,d;
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&d);
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        dp[n]=a[n];
        for(int i=n-1;i>=n-d&&i>=1;i--)dp[i]=a[i]+dp[n];
        for(int i=n-d-1;i>=1;)
        {
            int mn=dp[i+1];
            int pos=i+1;
            for(int j=i+2;j<=i+d;j++)
            {
               if(dp[j]<mn){mn=dp[j];pos=j;}
            }
            dp[i] = a[i] + mn;
            for(i--;i>=pos-d&&i>=1;i--)
            {
                dp[i] = a[i] + mn;
            }

        }
        printf("%d\n",dp[1]);
        //for(int i=1;i<=n;i++)cout<<dp[i]<<endl;
    }
    return 0;
}
