#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll gcd(ll a, ll b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
int main()
{
    int t;
    int n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ll a[n],ans;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        ans = a[0];
        for(int i=1;i<n;i++)
        {
            ans = gcd(ans,a[i]);
        }
        cout<<ans<<endl;
    }
}
