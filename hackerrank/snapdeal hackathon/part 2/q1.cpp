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
int charge[55],price[55],qual[55];
vector<int> shop[25];
map<int,int> pin,dis;
int m,n,k,l,r;
int dp[25][25][1005]
dp1[25][25][1005];
int main()
{
    cin>>m>>n>>k;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        pin[a]=b;
        dis[a] = i;
    }
    for(int i=0;i<n;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        charge[i] = pin[a];
        price[i] = b;
        qual[i] = c;
        shop[dis[a]].pb(i);
    }
    cin>>l>>r;
    for(int i=0;i<=m;i++)for(int j=0;j<=k;j++)for(int cost=0;cost<=r;cost++)dp[i][j][cost]=-inf;
    for(int i=0;i<=m;i++)dp[i][0][0]=0;
    for(int i=0;i<=m;i++)for(int j=0;j<=k;j++)for(int cost=0;cost<=r;cost++)dp1[i][j][cost]=0;
    for(int i=0;i<=m;i++)dp1[i][0][0]=1;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=k;j++)
        {
            for(int cost=1;cost<=r;cost++)
            {
                dp[i][j][cost] = dp[i-1][j][cost];
                for(int x=0;x<shop[i-1].size();x++)
                {
                    int sh = shop[i-1][x];
                    int temp = cost-price[sh]-charge[sh];
                    if(temp>=0)dp[i][j][cost] = max(dp[i][j][cost],qual[sh]+dp[i-1][j-1][temp]);
                }
                if(dp[i][j][cost]==dp[i-1][j][cost])dp1[i][j][cost] += dp1[i-1][j][cost];
                for(int x=0;x<shop[i-1].size();x++)
                {
                    int sh = shop[i-1][x];
                    int temp = cost-price[sh]-charge[sh];
                    if(temp>=0)
                    {
                        if(qual[sh]+dp[i-1][j-1][temp]==dp[i][j][cost])dp1[i][j][cost] += dp1[i-1][j-1][temp];
                    }
                }
            }
        }
    }
    int res=-inf;
    ll ways=0;
    for(int cost=l;cost<=r;cost++)
    {
        res = max(res,dp[m][k][cost]);
    }
    for(int cost=l;cost<=r;cost++)
    {
        if(dp[m][k][cost]==res)
        {
            ways += dp1[m][k][cost];
        }
    }
    if(res<0)
    {
        printf("-1\n");
    }
    else
    {
        printf("%d %d\n",res,ways);
    }
    return 0;

}

