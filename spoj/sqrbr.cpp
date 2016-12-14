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
ll s[50],dp[50][50];
int main()
{
    int t;
    scanint(t);
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        memset(s,0,sizeof(s));
        for(int i=0;i<k;i++)
        {
            int temp;
            cin>>temp;
            s[temp]=1;
        }
        dp[1][0]=0;
        dp[1][1]=1;
        for(int i=2;i<=2*n;i++)dp[1][i]=0;
        for(int i=2;i<=2*n;i++)
        {
            for(int j=0;j<=2*n;j++)
            {
                if(s[i])
                {
                    if(j==0)dp[i][j]=0;
                    else dp[i][j] = dp[i-1][j-1];
                }
                else
                {
                    if(j==0)dp[i][j] = dp[i-1][1];
                    else dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1];
                }
            }
        }
        cout<<dp[2*n][0]<<endl;
    }
    return 0;
}
