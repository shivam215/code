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
ll dp[20][5][210];
string s;
int c;
ll rec(int i,int j,int k)
{
    if(i==s.size())
    {
        if(j==0&&k<=c)return 1;
        return 0;
    }
    if(dp[i][j][k]!=-1)return dp[i][j][k];
    int st;
    if(i==0)st=1;
    else st=0;
    ll res=0;
    for(int l=st;l<=9;l++)
    {
        int diff = k + abs(s[i]-'0'-l);
        if(diff<=c)res = res + rec(i+1,(j+l)%3,diff);
    }
    return dp[i][j][k]=res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin>>s>>c;
    memset(dp,-1,sizeof(dp));
    ll res = rec(0,0,0);
    printf("%lld\n",res);
    return 0;
}
