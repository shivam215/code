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
int n,m,a[22],b[22];
int dp[22][(1<<20)+5];
int dp1[22][(1<<20)+5];
string s[22];
int rec(int i,int j)
{
    if(i==n)
    {
        return 0;
    }
    if(dp[i][j]!=-1)return dp[i][j];
    int res=0;
    for(int k=0;k<m;k++)
    {
        if(s[i][k]=='Y')
        {
            if(!(j&(1<<k)))
            {
                int temp = (j|(1<<k));
                res = max(res,a[i]*b[k]+rec(i+1,temp));
            }
        }
    }
    return dp[i][j]=res;
}
int rec1(int i,int j)
{
    if(i==n)
    {
        return 0;
    }
    if(dp1[i][j]!=-1)return dp1[i][j];
    int res=inf;
    for(int k=0;k<m;k++)
    {
        if(s[i][k]=='Y')
        {
            if(!(j&(1<<k)))
            {
                int temp = (j|(1<<k));
                res = min(res,a[i]*b[k]+rec1(i+1,temp));
            }
        }
    }
    return dp1[i][j]=res;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m;
    rep(i,0,n)cin>>a[i];
    rep(i,0,m)cin>>b[i];
    rep(i,0,n)cin>>s[i];
    memset(dp,-1,sizeof dp);
    memset(dp1,-1,sizeof dp1);
    int mx = rec(0,0);
    int mn = rec1(0,0);
    printf("%d %d\n",mn,mx);
    return 0;
}

