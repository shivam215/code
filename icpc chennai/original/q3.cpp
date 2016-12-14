#include <bits/stdc++.h>
#define inf 10000000
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
using namespace std;
int dp[102][10004],a[102],n,t[1005];
void upd(int i, int x)
{
    for (; i < 1005; i += i & -i) t[i] += x;
}
int get(int i)
{
    int s = 0;
    for (; i; i -= i & -i) s += t[i];
    return s;
}
int solve(int i,int j)
{
    if(i==n)
    {
        return j;
    }
    if(dp[i][j]!=-1)return dp[i][j];
    int res = inf;
    int left = get(1004) - get(a[i]+1);
    int right = get(a[i]-1);
    upd(a[i],1);
    res = min(res,solve(i+1,j+left));
    res = min(res,solve(i+1,j+right));
    return dp[i][j]=res;
}
int main()
{
    int test;
    scano(test);
    while(test--)
    {
        scano(n);
        rep(i,0,n)scano(a[i]),a[i]++;
        memset(t,0,sizeof t);
        memset(dp,-1,sizeof dp);
        int res = solve(0,0);
        printf("%d\n",res);
    }
    return 0;
}
