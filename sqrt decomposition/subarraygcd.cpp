#include <bits/stdc++.h>
#define B 320
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
int main()
{
    ios_base::sync_with_stdio(false);
    ll n,q,l,r,mx,mn,i,temp,j;
    ll a[100005],b[330],c[330];
    cin>>n>>q;
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        b[i/B] = max(b[i/B],a[i]);
        c[i/B] = gcd(c[i/B],a[i]);
    }
    while(q--)
    {
        cin>>l>>r;
        l--;r--;
        ll p = l/B;
        ll q = r/B;
        mx = 0;mn=0;
        if(p==q)
        {
            for(i=l;i<=r;i++)
            {
                mx = max(mx,a[i]);
                mn = gcd(mn,a[i]);
            }
        }
        else
        {
            for(i=l;i<=(p+1)*B-1;i++)
            {
                mx = max(mx,a[i]);
                mn = gcd(mn,a[i]);
            }
            for(i=p+1;i<q;i++)
            {
                mx = max(mx,b[i]);
                mn = gcd(mn,c[i]);
            }
            for(i=q*B;i<=r;i++)
            {
                mx = max(mx,a[i]);
                mn = gcd(mn,a[i]);
            }
        }
        printf("%lld %lld\n",mx,mn);
    }
    return 0;
}
