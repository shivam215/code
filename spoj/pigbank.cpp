#include <bits/stdc++.h>
#define inf 100000000
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
int dp[10004],v[10004],w[10004];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int e,f,n;
        cin>>e>>f>>n;
        for(int i=0;i<n;i++)cin>>v[i]>>w[i];
        int total = f-e;
        for(int i=0;i<10004;i++)dp[i]=inf;
        dp[0]=0;
        for(int i=1;i<=total;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i-w[j]>=0)dp[i] = min(dp[i],v[j]+dp[i-w[j]]);
                //dp[i] = min(dp[i],1+dp[i-v[j]); coin change condition
            }
            //cout<<dp[i]<<endl;
        }

        if(dp[total]>=inf)printf("This is impossible.\n");
        else printf("The minimum amount of money in the piggy-bank is %d.\n",dp[total]);


    }
    return 0;
}
