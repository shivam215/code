#include <bits/stdc++.h>
#define nifi INT_MIN
using namespace std;
typedef pair<int,int> ii;
int vis[100];
vector<int> g[100];
stack<int> st;
void topo(int root)
{
    vis[root]=1;
    for(int i=0;i<g[root].size();i++)
    {
        int child = g[root][i];
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
        cin>>a>>b;
        g[a].push_back(b);
    }
    memset(vis,0,sizeof(vis));
    for(int i=0;i<n;i++)if(!vis[i])topo(i);
    while(!st.empty())
    {
        cout<<st.top()<<' ';
        st.pop();
    }
    return 0;
}
