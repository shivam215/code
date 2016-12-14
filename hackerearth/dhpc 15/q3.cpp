#include <bits/stdc++.h>
#define inf 1000000000
#define mod 1000000007
#define scano(x) scanf("%d",&x)
#define scanll(x) scanf("%lld",&x)
#define scant(x,y) scanf("%d%d",&x,&y)
#define pb push_back
#define mp make_pair
#define ll long long int
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fe first
#define se second
#define MAX ((1<<15)+5)
using namespace std;
int dp[MAX];
int main()
{
    dp[0]=0,dp[1]=1;
    for(int i=2;i<MAX;i++)
    {
        dp[i]=inf;
        for(int j=1;j*j<=i;j++)
        {
            dp[i] = min(dp[i],1+dp[i-j*j]);
        }
    }
    while(1)
    {
        int n,k;
        scano(n);
        if(n==0)break;
        scano(k);
        ll res = dp[n]*k;
        printf("%lld\n",res);
    }
    return 0;
}
