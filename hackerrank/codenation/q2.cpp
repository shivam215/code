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
ll dp[105];
ll dp1[105][105];
ll solve(int n)
{
    if(n==1||n==0)return 1;
    if(dp[n]!=-1)return dp[n];
    ll res=0;
    for(int i=0;i<n;i++)
    {
        res = (res + solve(i)*solve(n-i-1))%mod;
    }
    return dp[n]=res;
}
int main()
{
    int t,n,h;
    cin>>t>>n>>h;
    dp[1][1]=1;
    for(int i=2;i<=100;i++)
    {
        dp1[1][i]=0;
    }
    for(int i=2;i<=100;i++)
    {
        dp1[i][1]=0;
    }
    for(int i=2;i<=100;i++)
    {
        for(int j=2;j<=100;j++)
        {

        }
    }


}
