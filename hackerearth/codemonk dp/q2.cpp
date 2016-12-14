#include <bits/stdc++.h>
#define mod 1000000007
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
int dp[1000006];
int main()
{
    int t,n;
    scanint(t);
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<1000006;i++)
    {
        dp[i] = (dp[i-1] + 1LL*(i-1)*dp[i-2])%mod;
    }
    while(t--)
    {
        scanint(n);

        printf("%d\n",dp[n]);
    }
    return 0;
}
