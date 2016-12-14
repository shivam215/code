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
ll dp[100][100];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int n = s.size();
        memset(dp,0,sizeof(dp));
        rep(i,0,n)dp[i][i]=1;
        for(int len=2;len<=n;len++)
        {
            for(int i=0;i<n-len+1;i++)
            {
                int j = i+len-1;
                //for not selecting ith element
                dp[i][j] = dp[i+1][j];
                //for selecting ith element and palindrome length is at least 2
                for(int k=i+1;k<=j;k++)
                {
                    if(s[i]==s[k])
                    {
                        dp[i][j] += 1 + dp[i+1][k-1];
                    }
                }
                //for selecting ith element and palindrome length is 1
                dp[i][j] +=1;
            }
        }
        cout<<dp[0][n-1]<<endl;
    }
    return 0;
}
//another recurrence
//either select ith element or select jth element subtract when both are not selected
//and add when both are getting selected
// if(s[i]==s[j])dp[i][j] = dp[i][j-1] + dp[i+1][j] - dp[i+1][j-1] + 1 + dp[i+1][j-1];
//either select ith element or select jth element subtract when both are not selected
// else dp[i][j] = dp[i][j-1] + dp[i+1][j] - dp[i+1][j-1];
