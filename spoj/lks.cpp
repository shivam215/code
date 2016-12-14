#include <bits/stdc++.h>
#define neginf -10000000000000000LL
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int dp[2][2000006],v[505],w[505];
int main()
{
    ios_base::sync_with_stdio(false);
    int k,n,i,j;
    cin>>k>>n;
    for(i=0;i<n;i++)cin>>v[i]>>w[i];
    for(i=0;i<2;i++)for(j=0;j<=k;j++)dp[i][j]=0;
    dp[0][w[0]]=v[0];
    for(i=1;i<n;i++)
    {
        for(j=0;j<=k;j++)
        {
            dp[i&1][j] = dp[(i-1)&1][j];
            if(j-w[i]>=0)
            {
                if(dp[i&1][j]<v[i]+dp[(i-1)&1][j-w[i]])
                {
                    dp[i&1][j] = v[i]+dp[(i-1)&1][j-w[i]];
                }
            }
        }
    }
    int res = 0;
    for(i=0;i<=k;i++)
    {
        res = max(res,dp[(n-1)&1][i]);
    }
    printf("%d\n",res);

}
