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
int dp[2][1003],a[1003],b[1003];
int main()
{
    int n;
    scanint(n);
    for(int i=0;i<n;i++)
    {
        scanint(a[i]);
        scanint(b[i]);
        if(a[i]>b[i])swap(a[i],b[i]);
    }
    dp[0][0] = a[0]+b[0];
    dp[1][0] = b[0]+a[0];
    for(int i=1;i<n;i++)
    {
        dp[0][i] = max(dp[1][i-1]+a[i] + b[i]-a[i-1]+abs(a[i-1]-b[i]),dp[0][i-1]+a[i]+b[i]-b[i-1]+abs(b[i-1]-b[i]));
        dp[1][i] = max(dp[1][i-1]+a[i] + b[i]-a[i-1]+abs(a[i-1]-a[i]),dp[0][i-1]+a[i]+b[i]-b[i-1]+abs(b[i-1]-a[i]));
    }
    dp[0][n-1] -= b[n-1];
    dp[1][n-1] -= a[n-1];
    cout<<max(dp[0][n-1],dp[1][n-1])<<endl;
    return 0;
}
