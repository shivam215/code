#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
ll dp[500][500];
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
            for(int i=0;i<s.size();i+=2)
            {
                for(int j=i+2;j<s.size();j+=2)
                {
                    for(int k=i;k<j;k+=2)
                    {
                        if(s[k+1]=='*')
                        {
                            dp[i][j] = max(dp[i][j],dp[i][k]*dp[k+2][j]);
                        }
                        else if(s[k+1]=='+')
                        {
                            dp[i][j] = max(dp[i][j],dp[i][k]+dp[k+2][j]);
                        }

                    }
                }
            }
            ll res = dp[0][s.size()-1];
            cout<<res<<endl;
    }
    return 0;

}
