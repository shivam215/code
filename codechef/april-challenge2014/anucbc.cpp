#include <bits/stdc++.h>
#define ll long long
#define mod 1000000009
using namespace std;
ll a[100005],dp[101][2];
int main()
{
    ios_base::sync_with_stdio(false);
    int t,n,q,m,i,j;
    cin>>t;
    while(t--)
    {
        cin>>n>>q;
        for(i=0;i<n;i++)cin>>a[i];
        while(q--)
        {
            cin>>m;
            memset(dp,0,sizeof(dp));
            dp[0][1]=1;
            for(i=0;i<n;i++)
            {
                for(j=0;j<m;j++)
                {
                    int temp = (((j+a[i])%m)+m)%m;
                    dp[temp][i&1] = (dp[temp][(i-1)&1] + dp[j][(i-1)&1]);
                    if(dp[temp][i&1]>=mod)dp[temp][i&1]%=mod;
                }
            }
            printf("%lld\n",dp[0][(n-1)&1]);
        }
    }
    return 0;
}
