#include <bits/stdc++.h>
using namespace std;
string a[51];
int dp[51][51];
int h,w;
int bfs(int i,int j)
{
    if(dp[i][j]>0)return dp[i][j];
    int c[8] = {1,1,0,-1,-1,-1,0,1};
    int b[8] = {0,1,1,1,0,-1,-1,-1};
    int res=0;
    for(int k=0;k<8;k++)
    {
        if(i+b[k]>=0 && i+b[k]<h && j+c[k]>=0 && j+c[k]<w && a[i+b[k]][j+c[k]]-a[i][j]==1)
        {
           res = max(res,bfs(i+b[k],j+c[k]));
        }
    }
    dp[i][j] = res+1;
    return res+1;
}
int main()
{
    int i,j;
    cin>>h>>w;
    int test=1;
    while(h>0 || w>0)
    {
    int res=0;
    memset(dp,0,sizeof(dp));
    for(i=0;i<h;i++)cin>>a[i];
    for(i=0;i<h;i++)for(j=0;j<w;j++){if(a[i][j]=='A')res=max(res,bfs(i,j));}
    cout<<"Case "<<test<<": "<<res<<endl;
    cin>>h>>w;
    test++;
    }
    return 0;
}
