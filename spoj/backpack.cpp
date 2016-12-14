#include <bits/stdc++.h>
#define inf 100000000000000000LL
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
int n,vmax;
int mark[100],cost[100],vol[100];
vector<int> adj[100];
ll dp[100][320005];
ll solve(int i,int j)
{
    if(i==n)
    {
        if(j<=vmax)return 0;
        return -inf;
    }
    if(dp[i][j]!=-1)return dp[i][j];
    ll res=-inf;
    if(!mark[i])
    {
        if(j+vol[i]<=vmax)res = max(res,cost[i]*vol[i]+solve(i+1,j+vol[i]));
        if(adj[i].size()>=1)
        {
            int a = adj[i][0];
            if(j+vol[a]+vol[i]<=vmax)res = max(res,cost[a]*vol[a]+cost[i]*vol[i]+solve(i+1,j+vol[a]+vol[i]));
            if(adj[i].size()==2)
            {
                int b = adj[i][1];
                if(j+vol[b]+vol[i]<=vmax)res = max(res,cost[b]*vol[b]+cost[i]*vol[i]+solve(i+1,j+vol[b]+vol[i]));
                if(j+vol[a]+vol[b]+vol[i]<=vmax)
                    res = max(res,cost[a]*vol[a]+cost[i]*vol[i]+cost[b]*vol[b]+solve(i+1,j+vol[a]+vol[b]+vol[i]));
            }
        }
    }
    res = max(res,solve(i+1,j));
    return dp[i][j]=res;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        memset(mark,0,sizeof mark);
        rep(i,0,100)adj[i].clear();
        memset(dp,-1,sizeof dp);
        cin>>vmax>>n;
        rep(i,0,n)
        {
            int a;
            cin>>vol[i]>>cost[i]>>a;
            if(a!=0)adj[a].pb(i),mark[i]=1;
        }
        ll res = solve(0,0);
        printf("%lld\n",res);
    }
    return 0;
}
