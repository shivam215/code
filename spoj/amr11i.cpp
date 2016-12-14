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
int vis[70004],ans[7004],hat[7004],dea[7004];
vector<int> g[7004];
void dfs(int root)
{
    vis[root]=1;
    rep(i,0,g[root].size())
    {
        int ch = g[root][i];
        if(!vis[ch])
        {
            dfs(ch);
            int res=ans[ch];
            if(hat[ch]>=hat[root]&&hat[ch]<=dea[root])res++;
            ans[root]=max(ans[root],res);
        }
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        rep(i,0,7004)g[i].clear();
        memset(vis,0,sizeof(vis));
        memset(ans,0,sizeof(ans));
        for(int i=0;i<n;i++)
        {
            int p;
            cin>>p>>hat[i]>>dea[i];
            if(p!=-1){g[i].pb(p);g[p].pb(i);}
        }
        dfs(0);
        rep(i,0,n)printf("%d ",ans[i]);
        printf("\n");
    }
    return 0;
}
