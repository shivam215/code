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
#define MAX 31622777
using namespace std;
int main()
{
    ll m,h1,a1,x1,y1,h2,a2,x2,y2;
    cin>>m;
    cin>>h1>>a1>>x1>>y1>>h2>>a2>>x2>>y2;
    int cnt=0;
    ll h11 = h1;
    while(cnt<=m&&h11!=a1)
    {
        h11 = (x1*h11 + y1)%m;
        cnt++;
    }
    if(cnt>m)
    {
        cout<<-1<<endl;
        return 0;
    }
    int cnt1=0;
    ll h22=h2;
    while(cnt1<cnt)
    {
        h22 = (x2*h22+y2)%m;
        cnt1++;
    }
    if(h22==a2)
    {
        cout<<cnt<<endl;
        return 0;
    }
    ll ans = cnt;
    cnt=1;
    ll h=(x1*h11+y1)%m;
    while(cnt<=m&&(h!=h11))
    {
        h = (x1*h+y1)%m;
        cnt++;
    }
    if(cnt>m)
    {
        cout<<-1<<endl;
        return 0;
    }
    ll c=1,d=0;
    for(int i=0;i<cnt;i++)
    {
        c = (c*x2)%m;
        d = (d*x2+y2)%m;
    }
    ll e = h22;
    int f=0;
    while(f<=m&&e!=a2)
    {
        e = (c*e+d)%m;
        f++;
    }
    if(f>m)
    {
        cout<<-1<<endl;
        return 0;
    }
    ans = ans + 1LL*f*cnt;
    cout<<ans<<endl;
    return 0;
}

