//http://www.spoj.com/problems/DQUERY/ (nlogn solution)

#include <bits/stdc++.h>
#define inf 100000000000014LL
#define mod 1000000007
#define scano(x) scanf("%d",&x)
#define scanll(x) scanf("%lld",&x)
#define scant(x,y) scanf("%d%d",&x,&y)
#define pb push_back
#define mp make_pair
#define ll long long int
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fe first
#define se second
#define MAX 30004
using namespace std;
int a[MAX],freq[1000006],t[MAX],n,last[1000006],next[MAX],ans[200005];
vector<pair<int,pair<int,int> > > v;
void upd(int i,int val)
{
    for(;i<=n;i+=(i&(-i)))
    {
        t[i]+=val;
    }
}
int get(int i)
{
    int sum=0;
    for(;i>=1;i-=(i&(-i)))
    {
        sum += t[i];
    }
    return sum;
}
bool comp(pair<int,pii > x,pair<int,pii > y)
{
    return x.fe>y.fe;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    rep(i,1,n+1)cin>>a[i];
    for(int i=n;i>=1;i--)
    {
        if(last[a[i]])next[i] = last[a[i]];
        else next[i]=-1;
        last[a[i]] = i;
    }
    int q;
    cin>>q;
    rep(i,1,q+1)
    {
        int l,r;
        cin>>l>>r;
        v.pb(mp(l,mp(r,i)));
    }
    sort(v.begin(),v.end(),comp);
    int cur = n+1;
    rep(i,0,v.size())
    {
        int l = v[i].fe;
        int r = v[i].se.fe;
        int j = v[i].se.se;
        while(cur>l)
        {
            cur--;
            upd(cur,1);
            if(next[cur]!=-1)upd(next[cur],-1);
        }
        ans[j] = get(r);
    }
    rep(i,1,q+1)printf("%d\n",ans[i]);
    return 0;
}
