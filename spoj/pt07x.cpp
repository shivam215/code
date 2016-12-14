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
int dp[100005][2];
vector<int> adj[100005];
int solve(int root,int flag,int parent)
{
    if(dp[root][flag]!=-1)return dp[root][flag];
    int res;
    if(flag==0)
    {
        res=0;
        for(int i=0;i<adj[root].size();i++)
        {
            int ch = adj[root][i];
            if(ch!=parent)res+=solve(ch,1-flag,root);
        }
    }
    else
    {
        res=1;
        for(int i=0;i<adj[root].size();i++)
        {
            int ch = adj[root][i];
            int r1=inf,r2=inf;
            if(ch!=parent)
            {
                r1 = solve(ch,1-flag,root);
            }
            if(ch!=parent)
            {
                r2 = solve(ch,flag,root);
            }
            if(r1!=inf||r2!=inf)res = res + min(r1,r2);
        }
    }
    return dp[root][flag]=res;
}
int main()
{
    int n;
    scano(n);
    rep(i,0,n-1)
    {
        int a,b;
        scant(a,b);
        adj[a].pb(b);
        adj[b].pb(a);
    }
    memset(dp,-1,sizeof(dp));
    int res = min(solve(1,0,-1),solve(1,1,-1));
    cout<<res<<endl;
    return 0;
}
