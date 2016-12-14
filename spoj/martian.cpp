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
int yey[505][505],blog[505][505],dp[505][505],column[505][505],row[505][505];
int main()
{
    int n,m;
    while(1)
    {
    scant(n,m);
    if(n==0&&m==0)break;
    rep(i,1,n+1)rep(j,1,m+1)scano(yey[i][j]);
    rep(i,1,n+1)rep(j,1,m+1)scano(blog[i][j]);
    memset(dp,0,sizeof(dp));
    memset(row,0,sizeof(row));
    memset(column,0,sizeof(column));
    rep(i,1,n+1)rep(j,1,m+1)
    {
        column[i][j] = column[i-1][j] + blog[i][j];
        row[i][j] = row[i][j-1] + yey[i][j];
    }
    rep(i,1,n+1)rep(j,1,m+1)
    {
        dp[i][j] = max(dp[i][j-1]+column[i][j],dp[i-1][j]+row[i][j]);
    }
    printf("%d\n",dp[n][m]);
    }
    return 0;
}
