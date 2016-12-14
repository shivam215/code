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
vector<int> adj[100005];
int a[100005],m;
int solve(int root,int parent,int j)
{
    if(parent!=-1&&adj[root].size()==1)
    {
        if(a[root]==1)j++;
        if(j<=m)return 1;
        return 0;
    }
    int res=0;
    for(int i=0;i<adj[root].size();i++)
    {
        int ch = adj[root][i];
        if(ch!=parent)
        {
            if(a[root]==1)
            {
                if(j+1<=m)res = res+solve(ch,root,j+1);
            }
            else res = res + solve(ch,root,0);
        }
    }
    return res;
}
int main()
{
    int n;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=0;i<n-1;i++)
    {
        int c,d;
        cin>>c>>d;
        adj[c].pb(d);
        adj[d].pb(c);
    }
    int res = solve(1,-1,0);
    cout<<res<<endl;
    return 0;
}
