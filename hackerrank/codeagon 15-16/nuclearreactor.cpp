#include <bits/stdc++.h>
#define inf 10000000
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
string s1,s2,s3;
int dp[102][102][102];
int prefix[102];
int solve(int i,int j,int k)
{
    if(k==s3.size())return -inf;
    if(i==s1.size()||j==s2.size())return 0;
    if(dp[i][j][k]!=-1)return dp[i][j][k];
    int res=0;
    if(s1[i]==s2[j])
    {
        if(s1[i]==s3[k])
        {
            res = max(res,1 + solve(i+1,j+1,k+1));
        }
        else
        {
            if(k>0)res = solve(i,j,prefix[k-1]);
            else res=1+solve(i+1,j+1,k);
        }
    }
    res = max(res,max(solve(i+1,j,k),solve(i,j+1,k)));
    return dp[i][j][k]=res;
}
int main()
{
    cin>>s1>>s2>>s3;
    prefix[0] = 0;
    for(int i=1;i<s3.size();i++)
    {
        int j = prefix[i-1];
        while(j>0 && s3[i]!=s3[j])
            j = prefix[j-1];
        if(s3[i] == s3[j]) j+=1;
        prefix[i] = j;
    }
    memset(dp,-1,sizeof(dp));
    int res = solve(0,0,0);
    cout<<res<<endl;
    return 0;
}
