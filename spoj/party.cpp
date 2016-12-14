#include <bits/stdc++.h>
#define scanint(x) scanf("%d",&x)
#define scanll(x) scanf("%lld",&x)
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int dp[102][505],w[102],v[102];
int main()
{
    while(1)
    {
        int cost,n;
        cin>>cost>>n;
        if(cost==0&&n==0)break;
        for(int i=0;i<n;i++)
        {
            cin>>w[i]>>v[i];
        }
        for(int i=0;i<102;i++)for(int j=0;j<505;j++)dp[i][j] = 0;
        dp[0][w[0]] = v[0];
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=cost;j++)
            {
                dp[i][j] = dp[i-1][j];
                if(j-w[i]>=0)dp[i][j] = max(dp[i][j],v[i]+dp[i-1][j-w[i]]);
            }
        }
        int res = 0,in=-1;
        for(int i=0;i<=cost;i++)
        {
            if(res<dp[n-1][i])
            {
                res = dp[n-1][i];
                in = i;
            }
        }
        cout<<in<<' '<<res<<endl;
    }
    return 0;
}
