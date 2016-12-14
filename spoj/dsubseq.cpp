#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;
int main()
{
    int t;
    string s;
    int pos[1000];
    ll dp[100005],total[100005];
    cin>>t;
    while(t--)
    {
        cin>>s;
        memset(dp,0,sizeof(dp));
        memset(total,0,sizeof(total));
        memset(pos,-1,sizeof(pos));
        dp[0]=1;
        total[0]=1;
        for(int i=0;i<s.size();i++)
        {
            dp[i+1] = total[i];
            if(pos[s[i]]!=-1)dp[i+1] = ((dp[i+1] - total[pos[s[i]]-1])%mod + mod)%mod;
            pos[s[i]]=i+1;
            total[i+1] = (total[i] + dp[i+1])%mod;
            //cout<<dp[i+1]<<' '<<total[i+1]<<endl;
        }
        cout<<total[s.size()]<<endl;
    }
    return 0;
}
