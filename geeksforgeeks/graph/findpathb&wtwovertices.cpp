#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int vis[100];
vector<int> g[100];
vector<int> path;
int flag=0;
int dfs(int root,int dest)
{
    vis[root]=1;
    path.push_back(root);
    if(root==dest)
    {
        return 1;
        /*rep(i,0,path.size())cout<<path[i]<<' ';
        path.pop_back();
        return;*/
    }
    rep(i,0,g[root].size())
    {
        int child = g[root][i];
        if(!vis[child])if(dfs(child,dest))return 1;;
    }
    path.pop_back();
    return 0;
}
int main()
{
    int n,e,a,b,src,dest;
    cin>>n>>e;
    rep(i,0,e)
    {
        cin>>a>>b;
        g[a].push_back(b);
    }
    cin>>src>>dest;
    if(dfs(src,dest))
    {
       rep(i,0,path.size())cout<<path[i]<<' ';
    }
    return 0;
}
