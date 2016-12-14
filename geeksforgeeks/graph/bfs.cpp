#include <bits/stdc++.h>
#define pb push_back
using namespace std;
vector<int> g[100];
int vis[100];
void bfs(int root)
{
    queue<int> q;
    q.push(root);
    vis[root]=1;
    while(!q.empty())
    {
        int s = q.front();
        cout<<s<<' ';
        q.pop();
        for(int i=0;i<g[s].size();i++)
        {
            int child = g[s][i];
            if(!vis[child])
            {
                vis[child]=1;
                q.push(child);
            }
        }
    }
}
int main()
{
    int n,e,i,a,b;
    cin>>n>>e;
    for(i=0;i<e;i++)
    {
        cin>>a>>b;
        g[a].pb(b);
        //g[b].pb(a);
    }
    bfs(2);
    return 0;
}

