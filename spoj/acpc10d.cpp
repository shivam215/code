#include <bits/stdc++.h>
#define inf 10000000000000LL
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
ll dp[100005][5];
int cost[100005][5];
int n;
ll rec(int i,int j)
{
    if(i==n-1&&j==1)
    {
        return cost[i][j];
    }
    if(dp[i][j]!=-1)return dp[i][j];
    ll res = inf;
    if(j+1<3)res = min(res,rec(i,j+1));
    if(i+1<n)
    {
        res = min(res,rec(i+1,j));
        if(j-1>=0)res = min(res,rec(i+1,j-1));
        if(j+1<3)res = min(res,rec(i+1,j+1));
    }
    if(res!=inf)return dp[i][j]=cost[i][j]+res;
    else return inf;
}
int main()
{
    int test=1;
    while(1)
    {
        scano(n);
        if(n==0)break;
        for(int i=0;i<n;i++)
        {
            scant(cost[i][0],cost[i][1]);
            scano(cost[i][2]);
        }
        memset(dp,-1,sizeof(dp));
        ll res= rec(0,1);
        printf("%d. %lld\n",test,res);
        test++;
    }
    return 0;
}
