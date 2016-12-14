#include <bits/stdc++.h>
#define inf 100000000
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
using namespace std;
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
map<char,int> ma;
vector<int> g[1000006];
int vis[1000006];
string s[1003];
void dfs(int root)
{
    vis[root]=1;
    rep(i,0,g[root].size())
    {
        int ch = g[root][i];
        if(!vis[ch])dfs(ch);
    }
}
int main()
{
    int n,m;
    scant(n,m);
    rep(i,0,n)cin>>s[i];
    ma['E']=0;ma['W']=1;ma['N']=2;ma['S']=3;
    rep(i,0,n)
    {
        rep(j,0,m)
        {
            int temp = ma[s[i][j]];
            int a = i + dx[temp];
            int b = j + dy[temp];
            g[i*m+j].pb(a*m+b);
            g[a*m+b].pb(i*m+j);
        }
    }
    int cnt=0;
    rep(i,0,n*m)
    {
        if(!vis[i])
        {
            dfs(i);
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;

}

