#include <bits/stdc++.h>
#define inf 1000000000
#define mod 1000000007
#define scano(x) scanf("%d",&x)
#define scanl(x) scanf("%lld",&x)
#define scanll(x,y) scanf("%lld%lld",&x,&y)
#define scant(x,y) scanf("%d%d",&x,&y)
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fe first
#define se second
using namespace std;
ll a[2003],b[2003],c[2003];
map<pll,int> mymap;
pll fin(ll x, ll y)
{
    return mp(x/__gcd(x,y),y/__gcd(x,y));
}
int main()
{
    freopen("q2s.in","r",stdin);
    freopen("q2s.out","w",stdout);
    int t;
    scano(t);
    rep(test,1,t+1)
    {
        int n1,n2,n3;
        scant(n1,n2);
        scano(n3);
        rep(i,0,n1)scanl(a[i]);
        rep(i,0,n2)scanl(b[i]);
        rep(i,0,n3)scanl(c[i]);
        mymap.clear();
        rep(i,0,n1)
        {
            rep(j,0,n3)
            {
                pll p = fin(a[i],c[j]);
                mymap[p]=1;
            }
        }
        int m;
        scano(m);
        printf("Case #%d:\n",test);
        while(m--)
        {
            ll p,q;
            scanll(p,q);
            int flag=0;
            rep(i,0,n2)
            {
                rep(j,0,n2)
                {
                    if(i==j)continue;
                    ll e = b[i]*p;
                    ll f = b[j]*q;
                    pll p = fin(e,f);
                    if(mymap[p]==1)
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag)break;
            }
            if(flag)printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}

