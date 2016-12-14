#include <bits/stdc++.h>
#define inf 1000000000
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
ll dp[102][102],a[102];
int main()
{
    int n;
    cin>>n;
    rep(i,0,n)cin>>a[i];
    rep(i,0,n-1)
    {
        if(a[i]<0 && a[i+1]+a[i]==0)dp[i][i+1]=1;
    }
    for(int l=3;l<=n;l++)
    {
        for(int i=0;i<n-l+1;i++)
        {
            int j = i+l-1;
            if(a[i]<0&&a[j]+a[i]==0)
            {
                dp[i][j] = ((dp[i][j-1] + dp[i+1][j] - dp[i+1][j-1] + 1 + dp[i+1][j-1])%mod+mod)%mod;
            }
            else
            {
                dp[i][j] = (dp[i][j-1] + dp[i+1][j] - dp[i+1][j-1])%mod;
            }
        }
    }
    cout<<dp[0][n-1]<<endl;
    return 0;
}
