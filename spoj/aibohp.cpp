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
int dp[6105][6105];
int main()
{
    int t;
    string s;
    cin>>t;
    while(t--)
    {
        cin>>s;
        int n = s.size();
        if(n==1)
        {
            cout<<0<<endl;
            continue;
        }
        for(int i=0;i<n;i++)dp[i][i]=0;
        for(int i=0;i<n-1;i++)
        {
            if(s[i]==s[i+1])dp[i][i+1]=0;
            else dp[i][i+1]=1;
        }
        for(int l=3;l<=n;l++)
        {
            for(int i=0;i<n-l+1;i++)
            {
                int j = i+l-1;
                if(s[i]==s[j])dp[i][j] = dp[i+1][j-1];
                else dp[i][j] = min(dp[i+1][j],dp[i][j-1])+1;
            }
        }
        cout<<dp[0][n-1]<<endl;

    }
    return 0;
}
