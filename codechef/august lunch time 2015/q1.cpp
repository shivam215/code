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
ll a[500005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n,mn;
        cin>>n;
        for(int i=0;i<n;i++)cin>>a[i];
        mn=a[0];
        for(int i=1;i<n;i++)
        {
            mn = min(mn,a[i]);
        }
        cout<<mn*(n-1)<<endl;
    }
    return 0;
}
