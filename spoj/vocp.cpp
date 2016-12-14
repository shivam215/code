#include <bits/stdc++.h>
#define inf 1000000000
#define mod 1000000007
#define scano(x) scanf("%d",&x)
#define scanll(x) scanf("%lld",&x)
#define scant(x,y) scanf("%d%d",&x,&y)
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fe first
#define se second
using namespace std;
void dfs(int root,int flag,int parent)
{

    for(int i=0;i<adj[root].size();i++)
    {
        int ch = adj[root][i];
        if(ch!=parent)
        {

        }
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        rep(i,0,n-1)
        {
            int a,b;
            cin>>a>>b;
            adj[a].pb(b);
            adj[b].pb(a);
        }

    }
}
