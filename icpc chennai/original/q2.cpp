#include <bits/stdc++.h>
#define inf 1000000000
#define epsilon 0.0001
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
double dp[1003][1003];
int choice[1003],n;
double solve(int i,int j)
{
    if(i==n)
    {
        return (double)j;
    }
    if(dp[i][j]!=-1)return dp[i][j];
    double res;
    if(choice[i]!=-1)
    {
        res = solve(i+1,j);
    }
    else
    {
        res = 0.5*solve(i+1,j);
        res = res + 0.5*solve(i+1,j+1);
    }
    return dp[i][j]=res;
}
int main()
{
    int t;
    scano(t);
    while(t--)
    {
        scano(n);
        rep(i,0,n)scano(choice[i]);
        for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)dp[i][j]=-1;
        double res = solve(1,1);
        printf("%.6f\n",res);
    }
    return 0;
}
