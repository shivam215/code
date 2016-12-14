#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[5005];
int main()
{
    ios_base::sync_with_stdio(false);
    string s;
    cin>>s;
    while(s[0]!='0')
    {
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int i=1;i<s.size();i++)
        {
            if(s[i]!='0')dp[i] = dp[i-1];
            int num = 10*(s[i-1]-'0') + s[i]-'0';
            if(num>=10 && num<=26)
            {
                if(i-2>=0)dp[i]+=dp[i-2];
                else dp[i]+=1;
            }
        }
        cout<<dp[s.size()-1]<<endl;
        cin>>s;
    }
    return 0;
}
