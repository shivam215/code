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
int cnt[2][202],dp[202][202];
int main()
{
    int t,n;
    string s;
    cin>>t;
    while(t--)
    {
        cin>>n>>s;
        cnt[0][0]=0;
        cnt[1][0]=0;
        for(int i=1;i<=n;i++)
        {
            cnt[0][i] = cnt[0][i-1] + (s[i-1]=='0');
            cnt[1][i] = cnt[1][i-1] + (s[i-1]=='1');
        }
        for(int i=0;i<202;i++)for(int j=0;j<202;j++)dp[i][j]=0;
        for(int i=0;i<n;i++)dp[i][i] = (s[i]=='1');
        for(int l=2;l<=n;l++)
        {
            for(int i=0;i<n-l+1;i++)
            {
                for(int j=i;j<i+l-1;j++)
                {
                    int temp=0;
                    if((cnt[1][j+1]-cnt[1][i])>(cnt[0][j+1]-cnt[0][i]))temp = j-i+1;
                    dp[i][i+l-1] = max(dp[i][i+l-1],temp+dp[j+1][i+l-1]);
                }
                if((cnt[1][i+l]-cnt[1][i])>(cnt[0][i+l]-cnt[0][i]))
                {
                    dp[i][i+l-1] = max(dp[i][i+l-1],l);
                }

            }
        }
        cout<<dp[0][n-1]<<endl;

    }
    return 0;
}
