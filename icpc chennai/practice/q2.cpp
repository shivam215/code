#include <bits/stdc++.h>
#define inf 1000000000
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
using namespace std;
int n,k,a[100005],has[100005];
ll t[100005];
void upd(int i, int x)
{
    for (; i <= n; i += i & -i) t[i] += x;
}
ll get(int i)
{
    ll s = 0;
    for (; i; i -= i & -i) s += t[i];
    return s;
}
int main()
{
    int test;
    cin>>test;
    rep(j,1,test+1)
    {
        cin>>n>>k;
        int flag=1;
        memset(t,0,sizeof(t));
        memset(has,0,sizeof has);
        rep(i,0,n)
        {
            cin>>a[i];
            if(has[a[i]])flag=0;
            has[a[i]]=1;
        }
        ll cnt=0;
        for(int i=n-1;i>=0;i--)
        {
            cnt = cnt + get(a[i]-1);
            upd(a[i],1);
        }
        ll ans;
        if(cnt>k)ans = cnt-k;
        else
        {
            ll temp = k-cnt;
            if(flag==0)ans = 0;
            else ans = (temp%2);
        }
        printf("Case %d: %lld\n",j,ans);
    }
    return 0;
}
