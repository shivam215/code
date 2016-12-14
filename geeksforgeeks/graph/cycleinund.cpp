#include <bits/stdc++.h>
using namespace std;
vector<int> g[100];
int vis[100],rec[100];
bool dfs(int root)
{
    vis[root]=1;
    rec[root]=1;
    for(int i=0;i<g[root].size();i++)
    {
        int child = g[root][i];
        if(!vis[child])
        {
            if(dfs(child))return true;
        }
        else
        {
            if(rec[child])return true;
        }
    }
    rec[root]=0;
    return false;
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
    }
    cout<<dfs(0)<<endl;
    return 0;
}
