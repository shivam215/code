#include <bits/stdc++.h>
#define scanint(x) scanf("%d",&x)
#define scanll(x) scanf("%lld",&x)
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
ll a[300005];
int main()
{
    int n,k;
    cin>>n>>k;
    for(i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    ll res=0;
    for(i=0;i<n-1;i++)
    {
        res += a[i+1]-a[i];
    }
    cout<<res<<endl;
    return 0;
}
