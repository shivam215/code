#include <bits/stdc++.h>
#define inf 100000000
#define mod 761238923
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
int n;
ll dp[200][200];
ll solve(int i,int presum)
{
    if(i==n+1)
    {
        if(presum==n)return 1;
        return 0;
    }
    if(dp[i][presum]!=-1)return dp[i][presum];
    int j = i-presum;
    ll res=0;
    for(int k=0;k<=j;k++)
    {
        res = (res + solve(i+1,presum+k))%mod;
    }
    return dp[i][presum]=res;

}
int main()
{
    while(1)
    {
        cin>>n;
        if(n==0)break;
        memset(dp,-1,sizeof(dp));
        ll res = solve(1,0);
        cout<<res<<endl;
    }
    return 0;
}
