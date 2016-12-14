#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,x,y,ans,i,j,p,q;
    cin>>n>>x>>y;
    int a[n],b[n];
    int dp[n+1][x+1];
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=x;j++)
        {
            dp[i][j]=0;
        }
    }
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<n;i++)
    {
        cin>>b[i];
    }
    for(i=1;i<=n;i++)
    {
        dp[i][0] = dp[i-1][0] + b[i-1];
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=x&&j<=i;j++)
        {
            p=0;
            if(j<=x)
            {
                p = dp[i-1][j-1]+a[i-1];
            }
            q=0;
            if((i-j)<=y)
            {
                q = dp[i-1][j]+ b[i-1];
            }
            dp[i][j]= max(p,q);
        }
    }
    ans = 0;
    for(i=0;i<=x;i++)
    {
      if(dp[n][i]>ans)
            ans = dp[n][i];
    }
    cout<<ans<<endl;
    return(0);

}
