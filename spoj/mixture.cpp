#include <bits/stdc++.h>
#define inf 1000000000000000LL
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
ll dp[102][102],a[102],sum[102];
int main()
{
    ll n;
    while(cin>>n)
    {
    sum[0]=0;
    rep(i,1,n+1){cin>>a[i];sum[i] = sum[i-1]+a[i];}

    rep(i,0,102)rep(j,0,102)dp[i][j]=inf;
    for(int i=1;i<=n;i++)dp[i][i]=0;
    for(int len=2;len<=n;len++)
    {
        for(int i=1;i<=n-len+1;i++)
        {
            for(int k=i;k<i+len-1;k++)
            {
                ll a = (sum[k] - sum[i-1])%100;
                ll b = (sum[i+len-1] - sum[k])%100;
                dp[i][i+len-1] = min(dp[i][i+len-1],dp[i][k] + dp[k+1][i+len-1]+a*b);
            }
            //cout<<dp[i][i+len-1]<<' ';
        }
        //cout<<endl;
    }
    cout<<dp[1][n]<<endl;
    }
    return 0;
}
