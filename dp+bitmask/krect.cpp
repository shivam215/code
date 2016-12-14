#include <bits/stdc++.h>
#define scano(x) scanf("%d",&x)
#define scant(x,y) scanf("%d%d",&x,&y)
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int dp[104][104];
string str[104];
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<n;i++)cin>>str[i];
    int ans=0;
    rep(i,0,n)
    {
        rep(j,0,m)
        {
            memset(dp,0,sizeof(dp));
            rep(w,1,n-i+1)
            {
                rep(h,1,m-j+1)
                {
                    int a = i+w-1;
                    int b = j+h-1;
                    int s=0;
                    if(a-1>=0)s = dp[a-1][b];
                    if(b-1>=0)s = s|dp[a][b-1];
                    int in = str[a][b]-'A';
                    if(!((s>>in)&1))s = s + (1<<in);
                    int cnt = __builtin_popcount(s);
                    dp[a][b] = s;
                    if(cnt==k)ans++;
                    if(cnt>k)break;
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
