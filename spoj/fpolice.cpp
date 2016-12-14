#include <bits/stdc++.h>
#define inf 10000000000000LL
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
ll dp[55][55][1003],tim[102][102],risk[102][102];
int main()
{
    int test,n,t;
    while(true)
    {
        cin>>n>>t;
        if(n==0&&t==0)break;
        rep(i,0,n)rep(j,0,n)cin>>tim[i][j];
        rep(i,0,n)rep(j,0,n)cin>>risk[i][j];
        rep(i,0,n)rep(j,0,n)rep(k,0,t+1)dp[i][j][k]=inf;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                dp[i][j][tim[i][j]] = risk[i][j];
            }
        }
        for(int k=0; k<=t; k++)
        {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                    for(int l=0; l<n; l++)
                    {
                        if(l==i)continue;

                        if(k-tim[i][l]>=0)dp[i][j][k] = min(dp[i][j][k],risk[i][l]+dp[l][j][k-tim[i][l]]);
                    }
            }
        }
        }
        ll ans1 = inf,ans2;
        for(int i=0; i<=t; i++)
        {
            if(ans1>dp[0][n-1][i])
            {
                ans1 = dp[0][n-1][i];
                ans2 = i;
            }
        }
        cout<<ans1<<' '<<ans2<<endl;
    }
    return 0;
}
