#include <bits/stdc++.h>
#define inf 1000000000
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
int a[500005];
int dp[500005][2];
vector<int> adj[500005];
int dfs(int root,int flag,int parent)
{
    if(dp[root][flag]!=-1)return dp[root][flag];
    int res=0;
    if(flag==0)
    {
        for(int i=0;i<adj[root].size();i++)
        {
            int ch = adj[root][i];
            if(ch!=parent)
            {
                res = res + dfs(ch,1,root);
            }
        }
    }
    else
    {
        if(a[root]==1)res=0;
        else res=1;
        for(int i=0;i<adj[root].size();i++)
        {
            int ch = adj[root][i];
            if(ch!=parent)
            {
                res = res + min(dfs(ch,0,root),dfs(ch,1,root));
            }
        }
    }
    return dp[root][flag]=res;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        rep(i,1,n+1)cin>>a[i];
        rep(i,0,500005)adj[i].clear();
        rep(i,0,n-1)
        {
            int c,d;
            cin>>c>>d;
            adj[c].pb(d);
            adj[d].pb(c);
        }
        memset(dp,-1,sizeof(dp));
        int res = min(dfs(1,0,-1),dfs(1,1,-1));
        cout<<res<<endl;
    }
    return 0;
}
