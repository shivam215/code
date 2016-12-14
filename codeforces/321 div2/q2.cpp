#include <bits/stdc++.h>
#define inf 1000000000
#define mod 1000000007
#define scano(x) scanf("%d",&x)
#define scanll(x) scanf("%lld",&x)
#define scant(x,y) scanf("%d%d",&x,&y)
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fe first
#define se second
using namespace std;
ll cum[100005];
pair<ll,ll> m[100005];
ll n;
bool comp(pair<ll,ll> a,pair<ll,ll> b)
{
    return a.fe<b.fe;
}
int bin(ll x)
{
    int low=1,high=n;
    while(low<high-1)
    {
        int mid = (low+high)/2;
        if(m[mid].fe>=x && m[mid-1].fe<x)return mid-1;
        else if(m[mid].fe<x)low=mid+1;
        else high = mid-1;
    }
    if(m[low].fe>=x)return low-1;
    else if(m[high].fe>=x)return high-1;
    return n;
}
int main()
{
    ios_base::sync_with_stdio(false);
    ll d;
    cin>>n>>d;
    for(int i=1;i<=n;i++)
    {
        cin>>m[i].fe>>m[i].se;
    }
    sort(m+1,m+n+1,comp);
    for(int i=1;i<=n;i++)cum[i]=cum[i-1]+m[i].se;
    ll res=0;
    for(int i=1;i<=n;i++)
    {
        int pos = bin(m[i].fe+d);
        res = max(res,cum[pos]-cum[i-1]);
    }
    cout<<res<<endl;
    return 0;
}
