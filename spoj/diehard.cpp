#include <bits/stdc++.h>
#define scano(x) scanf("%d",&x)
#define scant(x,y) scanf("%d%d",&x,&y)
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int dp[1003][1003][3];
int a[2][3] = {{3,-5,-20},{2,-10,5}};
int solve(int i,int j,int prev)
{
    if(i<=0||j<=0)return 0;
    if(dp[i][j][prev]!=-1)return dp[i][j][prev];
    int res1 = solve(i+a[0][(prev+1)%3],j+a[1][(prev+1)%3],(prev+1)%3);
    int res2 = solve(i+a[0][(prev+2)%3],j+a[1][(prev+2)%3],(prev+2)%3);
    dp[i][j][prev] = 1+max(res1,res2);
    return dp[i][j][prev];
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        memset(dp,-1,sizeof(dp));
        int res = max(solve(n+a[0][0],m+a[1][0],0),max(solve(n+a[0][1],m+a[1][1],1),solve(n+a[0][2],m+a[1][2],2)));
        cout<<res<<endl;
    }
    return 0;
}
