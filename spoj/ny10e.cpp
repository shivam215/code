#include <bits/stdc++.h>
#define scanint(x) scanf("%d",&x)
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
ll dp[100][10];
int main()
{
    int t;
    cin>>t;
    memset(dp,0,sizeof(dp));
    rep(i,0,10)dp[1][i]=1;
    rep(i,2,65)
    {
        rep(j,0,10)
        {
            rep(k,0,j+1)
            {
                dp[i][j] = dp[i][j] + dp[i-1][k];
            }
        }
        ll sum=0;
        rep(j,0,10)sum+=dp[i][j];
        cout<<sum<<endl;
    }
    while(t--)
    {
        int test,n;
        scanint(test);
        scanint(n);
        ll sum=0;
        rep(i,0,10)sum = sum + dp[n][i];
        printf("%d %lld\n",test,sum);

    }
    return 0;
}
