#include <bits/stdc++.h>
#define inf 100000000
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
int dp[1003][2][1003];
int n,k,a[1003];
int solve(int i,int j,int sum)
{
    if(i==n)
    {
        if(sum<=k)return 0;
    }
    if(dp[i][j][sum]!=-1)return dp[i][j][sum];
    int res=0;
    if(j==0)
    {
        if(sum+a[i]<=k)res = a[i]+solve(i+1,1-j,sum+a[i]);
        res = max(res,solve(i+1,j,sum));
    }
    else
    {
        res = solve(i+1,0,sum);
    }
    return dp[i][j][sum]=res;

}
int main()
{
    int t;
    cin>>t;
    rep(test,1,t+1)
    {
        cin>>n>>k;
        for(int i=0;i<n;i++)cin>>a[i];
        memset(dp,-1,sizeof(dp));
        int res = solve(0,0,0);
        printf("Scenario #%d: %d\n",test,res);
    }
    return 0;
}
