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

int dp[100001][3];

int main()
{
    int n;
    int x,y,z,test;
    cin>>test;
    while(test--)
    {
        cin>>n>>x>>y>>z;
        dp[0][0]=x;
        dp[0][1]=y;
        dp[0][2]=z;
        rep(i,1,n)
        {
            cin>>x>>y>>z;

            dp[i][0]=min(dp[i-1][1],dp[i-1][2])+x;

             dp[i][1]=min(dp[i-1][0],dp[i-1][2])+y;

              dp[i][2]=min(dp[i-1][0],dp[i-1][1])+z;


        }

        cout<<min(min(dp[n-1][0],dp[n-1][1]),dp[n-1][2])<<"\n";
    }
    return 0;
}

