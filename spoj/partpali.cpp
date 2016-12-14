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
ll dp[25][1004];
int m,n;
ll fast(ll a,ll b)
{
    ll res=1;
    while(b>0)
    {
        if(b&1)res=(res*a)%m;
        a = (a*a)%m;
        b>>=1;
    }
    return res;
}
ll solve(int i,int val)
{
    if(i==n/2)
    {
        if(val==0)return 1;
        return 0;
    }
    if(dp[i][val]!=-1)return dp[i][val];
    int st;
    if(i==0)st=1;
    else st=0;
    ll ans=0;
    for(int j=st;j<=9;j++)
    {
        ll res = (val + fast(10,i)*j + fast(10,n-i-1)*j)%m;
        int flag=0;
        if((n&1)&(i==(n/2-1)))
        {
            for(int l=0;l<=9;l++)
            {
                ll temp = (res + fast(10,i+1)*l)%m;
                ans = ans + solve(i+1,temp);
            }
            flag=1;
        }
        if(!flag)ans = ans + solve(i+1,res);
    }
    return dp[i][val]=ans;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>m>>n;
        if(n==1)
        {
            int cnt=0;
            for(int i=1;i<=9;i++)if(i%m==0)cnt++;
            cout<<cnt<<endl;
            continue;
        }
        memset(dp,-1,sizeof(dp));
        cout<<solve(0,0)<<endl;
    }
    return 0;
}
