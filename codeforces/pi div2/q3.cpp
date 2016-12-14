#include <bits/stdc++.h>
#define mp make_pair
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
#include<bits/stdc++.h>
using namespace std;
map<ll,ll> m,m1,dp,dp1,ans,ans1;
int main()
{
    ios_base::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        ll temp;
        cin>>temp;

        if(temp%k==0)m1[temp/k]=m[temp/k];
        if(temp%k==0)dp1[temp/k] = dp[temp/k];

        m[temp]++;
        if(temp%k==0)dp[temp]=dp[temp]+m1[temp/k];
        if(temp%k==0)ans[temp] = ans[temp] + dp1[temp/k];
    }
    map<ll,ll>::iterator it;
    ll res=0;
    for(it=ans.begin();it!=ans.end();it++)
    {
        res = res + it->second;
    }
    printf("%lld\n",res);
    return 0;

}
