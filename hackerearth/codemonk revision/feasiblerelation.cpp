#include <bits/stdc++.h>
#define scano(x) scanf("%d",&x)
#define scant(x,y) scanf("%d%d",&x,&y)
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int vis[1000006],parent[1000006];
vector<int> adj[1000006];
vector< pii > conflict;
void dfs(int root,int v)
{
    vis[v]=1;
    parent[v]=root;
    for(int i=0;i<adj[v].size();i++)
    {
        int child = adj[v][i];
        if(!vis[child])dfs(root,child);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        rep(i,0,n+1)adj[i].clear();
        conflict.clear();
        while(k--)
        {
            int a,b;
            string ch;
            cin>>a>>ch>>b;
            if(ch=="=")
            {
                adj[a].pb(b);
                adj[b].pb(a);
            }
            else conflict.pb(mp(a,b));
        }
        rep(i,0,n+1){vis[i]=0;parent[i]=-1;}
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])dfs(i,i);
        }
        int flag=0;
        for(int i=0;i<conflict.size();i++)
        {
            int a = conflict[i].first;
            int b = conflict[i].second;
            if(parent[a]==parent[b])
            {
                flag=1;
                break;
            }

        }
        if(flag)printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}
