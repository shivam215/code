#include <bits/stdc++.h>
#define scanint(x) scanf("%d",&x)
#define scanll(x) scanf("%lld",&x)
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int dp[1003][3],a[1003];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    dp[0][a[0]%3]=a[0];
    for(int i=1;i<n;i++)
    {
        dp[i][a[i]%3] = max(dp[i-1][a[i]%3],dp[i-1][0] + a[i]);

        dp[i][(1+a[i])%3] = dp[i-1][(1+a[i])%3];
        if(dp[i-1][1]!=0)dp[i][(1+a[i])%3] = max(dp[i][(1+a[i])%3],dp[i-1][1] + a[i]);

        dp[i][(2+a[i])%3] = dp[i-1][(2+a[i])%3];
        if(dp[i-1][2]!=0)dp[i][(2+a[i])%3] = max(dp[i][(2+a[i])%3],dp[i-1][2] + a[i]);
        //cout<<dp[i][0]<<' '<<dp[i][1]<<' '<<dp[i][2]<<endl;
    }
    cout<<dp[n-1][0]<<endl;
}
