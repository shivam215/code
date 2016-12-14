#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    ll n,m,k,l,r;
    cin>>n>>m>>k;
    ll a[n+1];
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    while(k--)
    {
        cin>>l>>r;
        ll b[m+1];
        memset(b,0,sizeof(b));
        //int vis[m+1];
        //memset(vis,0,sizeof(vis));
        vector<ll> v[m+1];
        for(ll i=0;i<m+1;i++)v[i].clear();
        for(ll i=l;i<=r;i++)
        {
           b[a[i]]++;
           v[a[i]].push_back(i);
        }
        ll mx = 0;
        for(ll i=1;i<=m;i++)
        {
            if(b[i]>1)
            {
                ll p = v[i].size()-1;
                ll temp = abs(v[i][p]-v[i][0]);
                if(temp>mx)mx=temp;
            }
        }
        /*for(ll i=l;i<=r;i++)
        {
            if(!vis[a[i]])
            {
            ll p = v[a[i]].size()-1;
            ll temp = max(abs(v[a[i]][p]-i),abs(v[a[i]][0]-i));
            if(temp>mx)mx = temp;
            vis[a[i]]=1;
            }
        }*/
        cout<<mx<<endl;
    }
    return 0;
}
