#include <bits/stdc++.h>
#define inf 100000000
#define mod 1000000007
#define scano(x) scanf("%d",&x)
#define scanll(x) scanf("%lld",&x)
#define scant(x,y) scanf("%d%d",&x,&y)
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fe first
#define se second
using namespace std;
ll dp[15][256][256];
int ans[15];
int n;
ll solve(int i,int j,int sum)
{
    if(i==n&&sum==0)return 1;
    if(i==n&&sum>0)return 0;
    if(dp[i][j][sum]!=-1)return dp[i][j][sum];
    ll ans=0;
    for(int k=j;k<256;k++)
    {
       if(sum-k>=0)ans = ans + solve(i+1,k,sum-k);
    }
    return dp[i][j][sum] = ans;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        ll k;
        cin>>m>>n>>k;
        memset(dp,-1,sizeof(dp));
        int temp=m;
        int prev=1;
        for(int i=0;i<n;i++)
        {
            for(int j=prev;j<=256;j++)
            {
                if(temp-j<0)break;
                ll res = solve(i+1,j,temp-j);
                if(res>=k)
                {
                    ans[i] = j;
                    temp = temp-j;
                    prev=j;
                    break;
                }
                else
                {
                    k = k - res;
                }
            }
        }
        for(int i=0;i<n;i++)cout<<ans[i]<<' ';
        cout<<endl;
    }
    return 0;
}
