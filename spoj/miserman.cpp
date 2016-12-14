#include <bits/stdc++.h>
#define inf 10000000
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int dp[102][102],fare[102][102];
int main()
{
    int n,m,k;
    cin>>n>>m;
    rep(i,0,n)rep(j,0,m)cin>>fare[i][j];
    rep(i,0,m)dp[0][i] = fare[0][i];
    rep(i,1,n)
    {
        rep(j,0,m)
        {
            dp[i][j] = dp[i-1][j];
            if(j-1>=0)dp[i][j] = min(dp[i][j],dp[i-1][j-1]);
            if(j+1<m)dp[i][j] = min(dp[i][j],dp[i-1][j+1]);
            dp[i][j] += fare[i][j];
        }
    }
    int res = inf;
    rep(i,0,m)res = min(res,dp[n-1][i]);
    cout<<res<<endl;
    return 0;
}
