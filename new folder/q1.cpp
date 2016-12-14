#include <bits/stdc++.h>
#define inf 1000000000
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
ll dp[1000][1000];
int n,k;
ll solve(int i,int j)
{
    if(i==k)
    {
        if(j==n)return 1;
        return 0;
    }
    if(dp[i][j]!=-1)return dp[i][j];
    ll res=0;
    for(int l=0;l<=n;l++)
    {
        if(j+l<=n)res = res + solve(i+1,j+l);
    }
    return dp[i][j]=res;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        memset(dp,-1,sizeof(dp));
        cout<<solve(0,0)<<endl;

    }
    return 0;
}
