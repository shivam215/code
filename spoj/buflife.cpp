#include <bits/stdc++.h>
using namespace std;
vector<int> g[2003];
int vis[2003],color[2003];
bool bfs(int root)
{
    vis[root]=1;
    queue<int> q;
    q.push(root);
    color[root]=1;
    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        vis[v]=1;
        for(int i=0;i<g[v].size();i++)
        {
            int child = g[v][i];
            if(color[child]==-1){color[child] = 1-color[v];q.push(child);}
            else if(color[child]==color[v])return false;
        }
    }
    return true;

}
int main()
{
    int t,a,b,flag;
    cin>>t;
    for(int test=1;test<=t;test++)
    {
        flag=1;
        cin>>a>>b;
        memset(vis,0,sizeof(vis));
        for(int i=0;i<2003;i++)g[i].clear();
        memset(color,-1,sizeof(color));
        for(int i=1;i<=b;i++)
        {
            int x,y;
            cin>>x>>y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        for(int i=1;i<=a;i++)
        {
            if(!vis[i])
            {
                if(!bfs(i))flag=0;
            }
        }
        cout<<"Scenario #"<<test<<":"<<endl;
        if(!flag)cout<<"Suspicious bugs found!"<<endl;
        else cout<<"No suspicious bugs found!"<<endl;
    }
    return 0;
}

