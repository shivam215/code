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
ll dp[100005][2][4];
int a[100005],n;
ll solve(int i,int turn,int prev)
{
    if(i>=n)return 0;
    if(dp[i][turn][prev]!=-1)return dp[i][turn][prev];
    ll res =0;
    if(turn==0)
    {
        res = a[i]+solve(i+1,1-turn,1);
        if(i+1<n)
        {
            res = max(res,a[i]+a[i+1]+solve(i+2,1-turn,2));
        }
        if(i+2<n)res = max(res,a[i]+a[i+1]+a[i+2]+solve(i+3,1-turn,3));
    }
    else
    {
            res = solve(i+prev,1-turn,0);

    }
    dp[i][turn][prev]=res;
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)cin>>a[i];
        memset(dp,-1,sizeof(dp));
        ll res = solve(0,0,0);
        printf("%lld\n",res);
    }
    return 0;
}
