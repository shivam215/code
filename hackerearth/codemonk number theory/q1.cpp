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
int n,k;
ll dp[2000][20];
int a[20][30];
string s;
ll solve(int mask,int i)
{
    if(i==k)
    {
        return 1;
    }
    if(dp[mask][i]!=-1)return dp[mask][i];
    ll res=0;
    for(int j=0;j<n;j++)
    {
        if(a[j][s[i]-'a']>0)
        {
            if(mask&(1<<j))continue;
            int nmask = (mask|(1<<j));
            res = (res + a[j][s[i]-'a']*solve(nmask,i+1))%mod;
        }
    }
    return dp[mask][i]=res;
}
int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<6;j++)
        {
            char ch;
            cin>>ch;
            a[i][ch-'a']++;
        }
    }
    cin>>s;
    memset(dp,-1,sizeof(dp));
    ll res = solve(0,0);
    cout<<res<<endl;

}
