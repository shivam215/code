#include <bits/stdc++.h>
#define mod 1000000007
typedef long long ll;
using namespace std;
ll modulo(ll a,ll b,ll c){ll x=1,y=a;while(b>0){if(b%2 == 1)x=(x*y)%c;y=(y*y)%c;b=b>>1;}return x%c;}
int a[200000];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,i,j;
    ll ans,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ll dp[101][202] = {{0}};
        int freq[101] = {0};
        for(i=0;i<n;i++)cin>>a[i];
        for(i=0;i<n;i++)
        {
            ll cur = a[i];
            for(j=0;j<=200;j++)
            {
                int cd = j-100;
                int prev = cur - cd;
                if(prev<1 || prev>100)continue;
                if(cd==0)
                {
                    dp[cur][j] = (2*dp[cur][j] + 1)%mod;
                }
                else
                {
                    dp[cur][j] = (dp[cur][j] + dp[prev][j] + freq[prev])%mod;
                }
            }
            freq[cur]++;
        }
        ans=0;
        for(i=0;i<101;i++)
        {
            for(j=0;j<202;j++)
            {
                ans = (ans + dp[i][j])%mod;
            }
        }
        ans = (modulo(2,n,mod)-1-ans+mod)%mod;
        printf("%lld\n",ans);
    }
    return 0;
}
