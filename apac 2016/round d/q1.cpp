#include <bits/stdc++.h>
#define inf 1000000000
#define mod 1000000007
#define scano(x) scanf("%d",&x)
#define scanll(x) scanf("%lld",&x)
#define scant(x,y) scanf("%d%d",&x,&y)
#define pb push_back
#define mp make_pair
#define ll long long int
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fe first
#define se second
#define MAX 10000008
using namespace std;
bool vis[102][102];
int n,m;
string a[102];
void dfs(int i,int j)
{
    vis[i][j]=1;
    if(i+1<n&&!vis[i+1][j]&&a[i+1][j]=='1')dfs(i+1,j);
    if(i-1>=0&&!vis[i-1][j]&&a[i-1][j]=='1')dfs(i-1,j);
    if(j+1<m&&!vis[i][j+1]&&a[i][j+1]=='1')dfs(i,j+1);
    if(j-1>=0&&!vis[i][j-1]&&a[i][j-1]=='1')dfs(i,j-1);
}
int main()
{
    freopen("q1.in","r",stdin);
    freopen("q1.out","w",stdout);
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    rep(test,1,t+1)
    {
        cin>>n>>m;
        rep(i,0,n)cin>>a[i];
        int q;
        cin>>q;
        printf("Case #%d:\n",test);
        while(q--)
        {
            char type;
            cin>>type;
            if(type=='M')
            {
                int x,y,z;
                cin>>x>>y>>z;
                a[x][y] = (char)(z+'0');
            }
            else
            {
                rep(i,0,n)rep(j,0,m)vis[i][j]=0;
                int cnt=0;
                rep(i,0,n)
                {
                    rep(j,0,m)
                    {
                        if(a[i][j]=='1'&&!vis[i][j])
                        {
                            dfs(i,j);
                            cnt++;
                        }
                    }
                }
                printf("%d\n",cnt);
            }
        }
    }
}
