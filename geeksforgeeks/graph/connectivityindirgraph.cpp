#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int vis[100];
void dfs(int root,vector<int> *g)
{
    vis[root]=1;
    rep(i,0,g[root].size())
    {
        int child = g[root][i];
        if(!vis[child])dfs(child,g);
    }
}
int main()
{
    vector<int> g[100],trg[100];
    int n,e;
    cin>>n>>e;
    rep(i,0,e)
    {
        int a,b;
        cin>>a>>b;
        g[a].pb(b);
    }
    int flag=1;
    dfs(0,g);
    rep(i,0,n)if(!vis[i]){flag=0;break;}
    //cout<<flag<<endl;
    if(flag)
    {
        rep(i,0,n)rep(j,0,g[i].size())trg[g[i][j]].pb(i);
        memset(vis,0,sizeof(vis));
        dfs(0,trg);
        rep(i,0,n)if(!vis[i])flag=0;
    }
    if(flag)cout<<"yes"<<endl;
    else cout<<"no"<<endl;
    return 0;
}
