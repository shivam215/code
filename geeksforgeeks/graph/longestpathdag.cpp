#include <bits/stdc++.h>
#define nifi INT_MIN
using namespace std;
typedef pair<int,int> ii;
int dist[100],vis[100];
vector<ii> g[100];
stack<int> st;
void topo(int root)
{
    vis[root]=1;
    for(int i=0;i<g[root].size();i++)
    {
        int child = g[root][i].first;
        if(!vis[child])topo(child);
    }
    st.push(root);
}
int main()
{
    int n,e,a,b,c;
    cin>>n>>e;
    for(int i=0;i<e;i++)
    {
        cin>>a>>b>>c;
        g[a].push_back(ii(b,c));
    }
    for(int i=0;i<n;i++)dist[i]=nifi;
    dist[1]=0;
    memset(vis,0,sizeof(vis));
    for(int i=0;i<n;i++)if(!vis[i])topo(i);
    while(!st.empty())
    {
        int node = st.top();
        cout<<node<<endl;
        st.pop();
        if(dist[node]!=nifi)
        {
            for(int i=0;i<g[node].size();i++)
            {
                int child = g[node][i].first;
                int cost = g[node][i].second;
                if(dist[child]<dist[node]+cost)dist[child]=dist[node]+cost;
            }
        }
    }
    for (int i = 0; i < n; i++)
        (dist[i] == nifi)? cout << "INF ": cout << dist[i] << " ";

        return 0;
}
