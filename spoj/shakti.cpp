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
int dp[1000006];
int main()
{
    ios_base::sync_with_stdio(false);
    int t,n;
    vector<int> vec;
    cin>>t;
    while(t--)
    {
        cin>>n;
        dp[0]=1;dp[1]=0;dp[2]=1;dp[3]=0;
    for(int i=4;i<=n;i++)
    {
        int flag=0;
        for(int j=1;j*j<=i;j++)
    {
        if(i%j==0)
        {
            if(!dp[i-j])flag=1;
            if(!dp[i-i/j])flag=1;
        }
    }
        if(flag)dp[i]=1;
        else dp[i]=0;
    }
        if(dp[n]==1)printf("Thankyou Shaktiman\n");
        else printf("Sorry Shaktiman\n");
    }
    return 0;
}
