#include <bits/stdc++.h>
#define inf 1000000000
#define mod 1000000007
#define scano(x) scanf("%d",&x)
#define scanll(x) scanf("%lld",&x)
#define scant(x,y) scanf("%d%d",&x,&y)
#define pb push_back
#define mp make_pair
#define ll long long int
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fe first
#define se second
using namespace std;
ll dp[2][200005][22],a[200005];
int main()
{
    int n;
    ll k1,k2;
    cin>>n>>k1>>k2;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<20;j++)
        {
            dp[1][i][j] = dp[1][i-1][j] + ((a[i]&(1<<j))>0);
            dp[0][i][j] = dp[0][i-1][j] + ((a[i]&(1<<j))==0);
        }
    }
    int in=1;
    ll ans=0,ans1=0,ans2=0;
    for(int i=1; i<=n; i++)
    {
        if(i>1)
        {
        for(int k=0; k<20; k++)
        {
            if(a[i-1]&(1<<k))
            {
                ans1 = ans1 - 1LL*(in-i+1)*(1<<k);
                ans2 = ans2 - (dp[0][in][k] - dp[0][i-1][k])*(1<<k);
            }
            else
            {
                ans1 = ans1 - (dp[1][in][k] - dp[1][i-1][k])*(1<<k);
                ans2 = ans2 - (dp[1][in][k] - dp[1][i-1][k])*(1<<k);
            }
        }
        }
        while((ans1<=k1||ans2<=k2)&&(in+1)<=n)
        {
            for(int k=0; k<20; k++)
            {
                if(a[in+1]&(1<<k))
                {
                    ans1 = ans1 + 1LL*(in-i+1)*(1<<k);
                    ans2 = ans2 + (dp[0][in][k] - dp[0][i-1][k])*(1<<k);
                }
                else
                {
                    ans1 = ans1 + (dp[1][in][k] - dp[1][i-1][k])*(1<<k);
                    ans2 = ans2 + (dp[1][in][k] - dp[1][i-1][k])*(1<<k);
                }
            }
            in++;
        }
        if(ans1<=k1||ans2<=k2)break;
        ans = ans + n-in+1;
    }
    printf("%lld\n",ans);
    return 0;
}
