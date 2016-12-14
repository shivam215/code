#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int main()
{
    int t;
    ll a[10004],dp[10004],n;
    cin>>t;
    for(int j=1;j<=t;j++)
    {
        cin>>n;
        if(n==0)
        {
            cout<<"Case "<<j<<": "<<0<<endl;
            continue;
        }
        for(int i=0;i<n;i++)cin>>a[i];
        dp[0]=a[0];
        for(int i=1;i<n;i++)
        {
            dp[i] = dp[i-1];
            if(dp[i]<a[i]+(i>=2)*(dp[i-2]))dp[i]=a[i]+(i>=2)*(dp[i-2]);
        }
        cout<<"Case "<<j<<": "<<dp[n-1]<<endl;
    }
    return 0;
}
