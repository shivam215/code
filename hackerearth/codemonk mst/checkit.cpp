#include <bits/stdc++.h>
using namespace std;
int vis[5005];
vector<int> g[5005];
int dfs1(int root)
{
    vis[root]=1;
    int coun=0;
    for(int i=0;i<g[root].size();i++)
    {
        int child = g[root][i];
        if(!vis[child])coun+=dfs1(child);
    }
    return coun+1;
}
int dfs(int root,int parent)
{
    vis[root]=1;
    for(int i=0;i<g[root].size();i++)
    {
        int child = g[root][i];
        if(!vis[child])
        {
            if(dfs(child,root))return true;
        }
        else
        {
            if(child!=parent)return true;
        }
    }
    return false;

}
int main()
{
    int t,n,m,i,j,a,b;
    vector< pair<int,int> > edge;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        edge.clear();
        for(i=0;i<5005;i++)g[i].clear();
        for(i=0;i<m;i++)
        {
            cin>>a>>b;
            edge.push_back(make_pair(a,b));
        }
        for(i=0;i<n-1;i++)
        {
            int num;
            cin>>num;
            num--;
            a = edge[num].first;
            b = edge[num].second;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        int flag=1;
        memset(vis,0,sizeof(vis));
        if(dfs1(1)!=n)flag=0;
        memset(vis,0,sizeof(vis));
        if(dfs(1,-1))flag=0;
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
    return 0;
}
