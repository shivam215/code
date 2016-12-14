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
int a[2503][2503];
ll dp[2503][2503],row[2503],col[2503],dia[2503*3];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>a[i][j];
    memset(row,0,sizeof row);
    memset(col,0,sizeof col);
    memset(dia,0,sizeof dia);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(i==1&&j==1)dp[i][j]=a[i][j];
            else dp[i][j] = (a[i][j]*(row[i]+col[j]+dia[j-i+2503]))%mod;
            dia[j-i+2503] = (dia[j-i+2503] + dp[i][j])%mod;
            row[i] = (row[i] + dp[i][j])%mod;
            col[j] = (col[j] + dp[i][j])%mod;
        }
    }
    printf("%lld\n",dp[n][m]);
    return 0;
}

