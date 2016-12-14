#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
ll dp[102][102];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int test,n,k;
        cin>>test>>n>>k;
        if(k>n-1)
        {
            cout<<test<<' '<<0<<endl;
            continue;
        }
        memset(dp,0,sizeof(dp));
        rep(i,1,n+1)dp[i][i-1]=1;
        dp[1][0]=2;
        dp[0][0]=1;
        for(int i=2;i<=n;i++)
        {
            for(int j=0;j<=k;j++)
            {
                if(j<i-1)
                {
                    dp[i][j] = dp[i-1][j];
                    for(int l=0;l<=j;l++)
                    {
                        if(i-l-2>=0)dp[i][j] += dp[i-l-2][j-l];
                    }

                }
            }
            //cout<<endl;
        }
        cout<<test<<' '<<dp[n][k]<<endl;
    }
    return 0;
}
