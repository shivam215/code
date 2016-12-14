#include <bits/stdc++.h>
#define inf 100000000000000LL
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int dp[102][102];
int main()
{
    int t;
    string s;
    cin>>t;
    while(t--)
    {
        cin>>s;
        memset(dp,0,sizeof(dp));
        rep(i,0,s.size())
        {
            if(s[i]!='+'&&s[i]!='*')
            {
                dp[i][i] = s[i]-'0';
            }
        }
            for(int len=3;len<=s.size();len+=2)
            {
                for(int j=0;j<s.size();j+=2)
                {
                    for(int k=j;k<j+len-1;k+=2)
                    {
                            if(s[k+1]=='*')dp[j][j+len-1] = max(dp[j][j+len-1],dp[j][k]*dp[k+2][j+len-1]);

                            if(s[k+1]=='+')dp[j][j+len-1] = max(dp[j][j+len-1],(dp[j][k]+dp[k+2][j+len-1]));


                    }
                }
            }
            ll res1 = dp[0][s.size()-1];

            rep(i,0,102)rep(j,0,102)dp[i][j]=inf;
            rep(i,0,s.size())
        {
            if(s[i]!='+'&&s[i]!='*')
            {
                dp[i][i] = s[i]-'0';
            }
        }
            for(int len=3;len<=s.size();len+=2)
            {
                for(int j=0;j<s.size();j+=2)
                {
                    for(int k=j;k<j+len-1;k+=2)
                    {
                            if(s[k+1]=='*')dp[j][j+len-1] = min(dp[j][j+len-1],dp[j][k]*dp[k+2][j+len-1]);

                            if(s[k+1]=='+')dp[j][j+len-1] = min(dp[j][j+len-1],(dp[j][k]+dp[k+2][j+len-1]));


                    }
                }
            }
            ll res2 = dp[0][s.size()-1];
            cout<<res1<<' '<<res2<<endl;
    }
    return 0;

}
