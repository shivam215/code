#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ll dp[n+1];
        dp[0]=1;dp[1]=2;
        for(int i=2;i<=n;i++)dp[i]=dp[i-1]+dp[i-2];
        cout<<dp[n]<<endl;
    }
    return 0;
}
