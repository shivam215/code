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
int n;
ll dp[100][30];
ll rec(int i,int j)
{
    if(i==n)return 1;
    if(dp[i][j]!=-1)return dp[i][j];
    ll res=0;
    res = res + (j+1)*rec(i+1,j);
    if(j+1<26)res = res+rec(i+1,j+1);
    return dp[i][j]=res;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        memset(dp,-1,sizeof(dp));
        cout<<rec(1,0)<<endl;
    }
    return 0;
}
