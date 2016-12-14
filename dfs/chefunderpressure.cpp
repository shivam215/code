#include <bits/stdc++.h>
using namespace std;
int n,k,b;
vector<int> v[10004];
int vis[10004];
int parent[10004];
int a[10004],ab[102];
int dp[10004][102];
void dfs(int root)
{
    vis[root] = 1;
    dp[root][a[root]]=root;
    for(int i=0;i<v[root].size();i++)
    {
        int temp = v[root][i];
        if(!vis[temp])
        {
            dfs(temp);
            parent[temp]=root;
            for(int j=1;j<=k;j++)
            {
                dp[root][j] = min(dp[root][j],dp[temp][j]);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    int q,r,s;
    cin>>n>>k>>b;
    for(int i=1;i<n;i++)
    {
        cin>>r>>s;
        v[r].push_back(s);
        v[s].push_back(r);
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        ab[a[i]]=1;
    }
    parent[b]=-1;
    for(int i=0;i<10004;i++)for(int j=0;j<102;j++)dp[i][j]=INT_MAX;
    dfs(b);
    cin>>q;
    while(q--)
    {
        cin>>r>>s;
        if(!ab[s])
        {
            cout<<"-1"<<endl;
            continue;
        }
        //for(int i=1;i<=n;i++)for(int j=1;j<=k;j++)cout<<dp[i][j]<<endl;
        while(dp[r][s]>=INT_MAX&&parent[r]!=-1)r=parent[r];
        cout<<dp[r][s]<<endl;
    }
    return 0;
}
