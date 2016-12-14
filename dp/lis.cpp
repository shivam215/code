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
int dp[100][100],a[100],n;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for (int i = 1; i <= n; i++){
			for (int lastUp = i+1; lastUp <= n; lastUp++){
					dp[i][lastUp] = dp[i-1][lastUp];

					if (a[i] < a[lastUp])
						dp[i][lastUp] = max(dp[i][lastUp], 1+dp[i-1][i]);
			}
		}
		int res=0;
		for(int i=1;i<=n;i++)
        {
            res = max(res,dp[i-1][i]+1);
        }
        cout<<res<<endl;
    return 0;
}
