#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,k;
ll a[101][101];
bool solve(ll x, ll y, ll z)
{
    if(z>k)return false;
    if(x==0)return true;
    ll i = x-1,j=y;
    ll temp = a[x-1][y];
    if(y-1>=0)
    {
        if(a[x-1][y-1]<=temp)
        {
            i = x-1;
            j = y-1;
            temp = a[x-1][y-1];
        }
    }
    if(y+1<m)
    {
        if(a[x-1][y+1]<temp)
        {
            i = x-1;
            j=y+1;
            temp = a[x-1][y+1];
        }
    }
    solve(i,j,z+temp);
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k;
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<m;j++)cin>>a[i][j];
        }
        if(solve(n-1,0,a[n-1][0]))cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}

