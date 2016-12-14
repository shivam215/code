#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;
ll k;
vector<ll> adj[35];
ll solve(ll x, ll y, ll len)
{
    if(x==y && len<=k)return 1LL;
    if(len>k)return 0;
    ll res=0;
    for(ll i=0;i<adj[x].size();i++)
    {
        res = (res + solve(adj[x][i],y,len+1))%mod;
    }
    return res;
}
int main()
{
    ll n,m,i,x,y,q;
    cin>>n>>m>>k;
    for(i=0;i<m;i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
    }
    cin>>q;
    while(q--)
    {
        cin>>x>>y;
        cout<<solve(x,y,0)<<endl;
    }
    return 0;

}
