#include <bits/stdc++.h>
#define inf 100000000
using namespace std;
int main()
{
    int n,m,res;
    int cum[1003],p[1003],dp[30][1003]={};
    cin>>m>>n;
    cum[0]=0;
    int mx=0;
    for(int i=1;i<=n;i++) {cin>>p[i];cum[i]=cum[i-1]+p[i];mx=max(mx,p[i]);}
    if(m>=n){cout<<mx<<endl;return 0;}
    for(int i=0;i<=n;i++)dp[1][i] = cum[i];
    for(int i=1;i<=m;i++)dp[i][1] = p[1];

    for(int i=2;i<=m;i++)
    {
        for(int j=2;j<=n;j++)
        {
            res=inf;
            for(int k=1;k<=j;k++)
            {
                res = min(res,max(cum[j]-cum[j-k],dp[i-1][j-k]));
            }
            dp[i][j]=res;
        }
    }
    res=inf;
    for(int i=1;i<=m;i++)res=min(res,dp[i][n]);
    cout<<res<<endl;
    return 0;
}
