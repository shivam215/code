#include <bits/stdc++.h>
#define mod 100000000
#define ll unsigned long long
using namespace std;
int n,n1,n2,k1,k2;
ll dp[202][12][12][102];
ll f(int idx,int x,int y,int z)
{
    if(idx>n+1)return 0;
    if(idx<=n+1&&(x>k1||y>k2))return 0;
    if(idx==n+1)return 1;
    if(dp[idx][x][y][z]!=-1)return dp[idx][x][y][z];
    ll res = 0;
    if(z<n1) res = f(idx+1,x+1,0,z+1);
    if(idx-1-z<n2) res = (res +  f(idx+1,0,y+1,z))%mod;
    dp[idx][x][y][z] = res;
    return res;
}
int main()
{
    cin>>n1>>n2>>k1>>k2;
    n = n1+n2;
    memset(dp,-1,sizeof(dp));
    cout<<f(1,0,0,0)<<endl;
    return 0;
}
