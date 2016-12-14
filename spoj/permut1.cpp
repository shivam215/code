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
ll dp[100][100];
int n,k;
ll solve(int i,int j)
{
    if(i==1)
    {
        if(j==k)return 1;
        return 0;
    }
    if(dp[i][j]!=-1)return dp[i][j];
    ll res=0;
    for(int l=1;l<=i;l++)
    {
        if(l-1+j<=k)res = res + solve(i-1,l-1+j);
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
        cout<<solve(n,0)<<endl;
    }
    return 0;
}
