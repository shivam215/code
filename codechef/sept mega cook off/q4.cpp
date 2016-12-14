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
ll dp[5005][5005];
pair<ll,ll> a[5005];
int n;
bool comp(pii x,pii y)
{
    if(x.se!=y.se)return x.se>y.se;
    else return x.fe>y.fe;
}
void solve()
{
    memset(dp,0,sizeof(dp));
    dp[0][1]=a[0].fe;
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=i+1;j++)
        {
            dp[i][j] = max(dp[i-1][j],dp[i-1][j-1]+a[i].fe+(j-1)*a[i].se);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)cin>>a[i].fe;
        for(int i=0;i<n;i++)cin>>a[i].se;
        sort(a,a+n,comp);
        solve();
        for(int i=1;i<=n;i++)
        {
            cout<<dp[n-1][i];
            if(i<n)cout<<' ';
        }
        cout<<endl;
    }
}
