#include <bits/stdc++.h>
#define INF 10000
using namespace std;
int dp[200][200],vis[200][200],n,m;
string s[200];
int rec(int i,int j)
{
    vis[i][j]=1;
    if(s[i][j]=='1')return dp[i][j]=0;
    if(dp[i][j]!=-1)return dp[i][j];
    int res = INF;
    if(i+1<n && !vis[i+1][j])res = min(res,rec(i+1,j));
    if(i-1>=0 && !vis[i-1][j])res = min(res,rec(i-1,j));
    if(j+1<m && !vis[i][j+1])res = min(res,rec(i,j+1));
    if(j-1>=0 && !vis[i][j-1])res=min(res,rec(i,j-1));
    dp[i][j] = res+1;
    return dp[i][j];
}
int main()
{
    int t,i,j;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(i=0;i<n;i++)cin>>s[i];
        memset(vis,0,sizeof(vis));
        memset(dp,-1,sizeof(dp));
        for(i=0;i<n;i++)for(j=0;j<m;j++)if(s[i][j]=='1')dp[i][j]=0;
        rec(0,0);
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                cout<<dp[i][j]<<' ';
            }
            cout<<endl;
        }
    }
    return 0;
}
