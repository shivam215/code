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
int dp[205][205][2],n,m;
string s[205];
int solve(int x,int y, int right)
{
    if(dp[x][y][right]!=-1)return dp[x][y][right];
    int res=0;
    if(right)
    {
        if(y+1<m&&s[x][y+1]!='#')res = solve(x,y+1,right);
        if(x+1<n&&s[x+1][y]!='#')res = max(res,solve(x+1,y,1-right));
    }
    else
    {
        if(y-1>=0&&s[x][y-1]!='#')res = solve(x,y-1,right);
        if(x+1<n&&s[x+1][y]!='#')res = max(res,solve(x+1,y,1-right));
    }
    if(s[x][y]=='T')return dp[x][y][right]=res+1;
    return dp[x][y][right]=res;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        rep(i,0,n)cin>>s[i];
        if(s[0][0]=='#'){cout<<0<<endl;continue;}
        memset(dp,-1,sizeof(dp));
        cout<<solve(0,0,1)<<endl;
    }
    return 0;
}
