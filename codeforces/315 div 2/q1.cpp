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
    ll t,s,q;
    cin>>t>>s>>q;
    ll curr = s*q;
    ll ans=1;
    while(curr<t)
    {
        curr = curr*q;
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}
