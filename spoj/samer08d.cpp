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
int dp[1003][1003][100],n1,n2,k;
string s1,s2;
int solve(int i,int j,int len)
{
    if(i==n1||j==n2)
    {
        if(len>=k)return len;
        return 0;
    }
    if(dp[i][j][len]!=-1)return dp[i][j][len];
    int res=0;
    if(s1[i]==s2[j])
    {
        res = max(solve(i+1,j,len),max(solve(i,j+1,len),solve(i+1,j+1,len+1)));
    }
    else
    {
        if(len>=k)res=len;
        res = res + max(solve(i+1,j,0),solve(i,j+1,0));
    }
    return dp[i][j][len]=res;
}
int main()
{
    while(1)
    {
        cin>>k;
        if(k==0)break;
        cin>>s1>>s2;
        n1 = s1.size();
        n2 = s2.size();
        memset(dp,-1,sizeof(dp));
        int res = solve(0,0,0);
        cout<<res<<endl;
    }
}
