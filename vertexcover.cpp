#include <bits/stdc++.h>
#define inf 1000000000
#define mod 1000000007
#define scano(x) scanf("%d",&x)
#define scanll(x) scanf("%lld",&x)
#define scant(x,y) scanf("%d%d",&x,&y)
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector<ll>
#define pii pair<ll,ll>
#define vpii vector< pii >
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define fe first
#define se second
#define MAX 1000006
using namespace std;
ll k=1;
ll dp[100005][2],a[100005],node[100005];
vector<ll> g[100005];
ll dfs(ll root,ll parent,ll f)
{
    if(dp[root][f]!=-1)return dp[root][f];
    a[root]=0;
    ll r1=node[root],r2=0,res;
    rep(i,0,g[root].size())
    {
        ll ch = g[root][i];
        if(ch!=parent)
        {
            if(f==1)r1 = r1 + dfs(ch,root,0);
            else
            {
                r2 = r2 + max(dfs(ch,root,0),dfs(ch,root,1));
            }
        }
    }
    if(f==1)res=r1;
    else res=r2;
    return dp[root][f]=res;
}
int main()
{
    ll q;
    cin>>q;
    memset(dp,-1,sizeof dp);
    while(q--)
    {
        char ch;
        cin>>ch;
        if(ch=='A')
        {
            ll x;
            cin>>x;
            node[k] = x;
            a[k]=1;
            k++;
        }
        else if(ch=='B')
        {
            ll x,y;
            cin>>x>>y;
            g[x].pb(y);
            g[y].pb(x);
        }
        else
        {
            ll x;
            cin>>x;
            ll res = max(dfs(x,-1,0),dfs(x,-1,1));
            node[k]=res;
            a[k]=1;
            k++;
        }
    }
    ll res=0;
    rep(i,1,k)
    {
        if(a[i])
        {
            ll r1 = dfs(i,-1,0);
            ll r2 = dfs(i,-1,1);

            res = res + max(r1,r2);
        }
    }
    cout<<res<<endl;
    return 0;
}
