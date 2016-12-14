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
ll dp[10004][2],n;
ll solve(int i,int prev)
{
    if(i==n)return 1;
    if(dp[i][prev]!=-1)return dp[i][prev];
    ll res=0;
    if(prev==0)
    {
        res+=solve(i+1,1);
    }
    else
    {
        res+=solve(i+1,0)+solve(i+1,1);
    }
    dp[i][prev]=res;
    return res;

}
int main()
{
    cin>>n;
    memset(dp,-1,sizeof(dp));
    cout<<solve(1,0)+solve(1,1)<<endl;
    return 0;
}
