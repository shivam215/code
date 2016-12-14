#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
ll dp[202][202];
int main()
{
    ios_base::sync_with_stdio(false);
    int t,n,q;
    ll a[202];
    cin>>t;
    while(t--)
    {
        cin>>n>>q;
        for(int i=0;i<n;i++)cin>>a[i];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)
        {
            dp[i][1] = 1;
        }
        for(int i=2;i<=n;i++)
        {
            for(int j=i-1;j<n;j++)
            {
                for(int k=0;k<j;k++)
                {
                    if(a[j]>a[k])
                    {
                        dp[j][i] = (dp[j][i] + dp[k][i-1])%mod;
                    }
                }
            }
        }
        while(q--)
        {
            int x;
            ll res=0;
            cin>>x;
            for(int i=0;i<n;i++)
            {
                res = (res + dp[i][x])%mod;
            }
            cout<<res<<endl;
        }


    }
}
