#include <bits/stdc++.h>
#define inf 1000000009
#define mod 1000000007
#define scano(x) scanf("%d",&x)
#define scanll(x) scanf("%lld",&x)
#define scant(x,y) scanf("%d%d",&x,&y)
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fe first
#define se second
using namespace std;
int dp[10004][10004];
int pi[10004],as[10004];
int n;
int main()
{
    scano(n);
    for(int i=1;i<=n;i++)scant(pi[i],as[i]);
    for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)dp[i][j]=inf;
    dp[0][0]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(j-1>=0&&dp[i-1][j-1]!=inf)dp[i][j] = as[i]+dp[i-1][j-1];
            if(dp[i-1][j+1]!=inf)dp[i][j] = min(dp[i][j],pi[i]+dp[i-1][j+1]);
        }
    }
    printf("%d\n",dp[n][0]);
    return 0;
}
