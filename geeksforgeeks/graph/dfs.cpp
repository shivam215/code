#include <bits/stdc++.h>
using namespace std;
vector<int> g[100];
int vis[100];
void dfs(int root)
{
    vis[root]=1;
    cout<<root<<' ';
    for(int i=0;i<g[root].size();i++)
    {
       int child = g[root][i];
       if(!vis[child])dfs(child);
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    for(int i=0;i<e;i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        //g[b].push_back(b);
    }
    dfs(2);
    return 0;
}
