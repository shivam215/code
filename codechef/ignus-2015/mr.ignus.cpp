#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[100005][2];
int main()
{
    ios_base::sync_with_stdio(false);
    ll a[100005];
    ll t,i,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        dp[0][0]=0;dp[0][1]=a[0];
        for(i=1;i<n;i++)
        {
            dp[i][1] = dp[i-1][0] + a[i];
            dp[i][0] = max(dp[i-1][0],dp[i-1][1]);
        }
        cout<<max(dp[n-1][0],dp[n-1][1])<<endl;
    }
    return 0;
}
