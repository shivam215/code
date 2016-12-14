#include <bits/stdc++.h>
using namespace std;
int vis[10004];
vector<int> g[10004];
int d[10004];
void dfs(int root)
{
   vis[root]=1;
   for(int i=0;i<g[root].size();i++)
   {
       int child = g[root][i];
       if(!vis[child])
       {
           d[child] = d[root] + 1;
           dfs(child);
       }
   }
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t,n,a,b,i;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=0;i<10004;i++)g[i].clear();
        for(i=0;i<n-1;i++)
        {
            cin>>a>>b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        memset(vis,0,sizeof(vis));
        d[1]=0;
        dfs(1);
        int mx=0,node=1;
        for(i=1;i<=n;i++)
        {
            if(d[i]>mx)
            {mx=d[i];
            node = i;
            }
        }
        memset(vis,0,sizeof(vis));
        d[node]=0;
        dfs(node);
        mx=0;
        for(i=1;i<=n;i++)if(d[i]>mx)mx=d[i];

        if(mx>1)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
    return 0;
}
