#include <bits/stdc++.h>
#define inf 1000000000000000000LL
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
int a[3005];
int main()
{
    int n;
    cin>>n;
    rep(i,0,n)cin>>a[i];
    ll ans=-inf;
    rep(i,0,n)
    {
        int l=i,r=i+1;
        ll cur=0;
        while(l>=0&&r<n)
        {
            cur = cur + 1LL*a[l]*a[r];
            ans = max(ans,cur);
            if(cur<0)cur=0;
            l--;r++;
        }
    }
    rep(i,0,n)
    {
        int l=i-1,r=i+1;
        ll cur=0;
        while(l>=0 && r<n)
        {
            cur = cur + 1LL*a[l]*a[r];
            ans = max(ans,cur);
            if(cur<0)cur=0;
            l--;r++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
