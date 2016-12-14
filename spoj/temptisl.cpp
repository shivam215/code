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
int n,k,a,b;
ll dp[100][100];
ll solve(int i,int j)
{
    if(i==b)
    {
        if(j==k-1)return 1;
    }
    if(j!=-1)if(dp[i][j]!=-1)return dp[i][j];
    ll res=0;
    if(j+1<k){res = res + solve(((i+1)%n),j+1);
    res = res + solve(((i-1+n)%n),j+1);
    }
    return dp[i][j]=res;
}
int main()
{
    while(1)
    {
        cin>>n>>k;
        if(n==-1&&k==-1)break;
        cin>>a>>b;
        a--;b--;
        memset(dp,-1,sizeof(dp));
        ll res = solve(a,-1);
        cout<<res<<endl;
    }
    return 0;
}
