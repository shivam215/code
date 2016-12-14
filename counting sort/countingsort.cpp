#include <bits/stdc++.h>
#define mod 1000000
#define ll long long
#define RANGE 1000006
using namespace std;
ll coun[RANGE];
int main()
{
    ios_base::sync_with_stdio(false);
    int t,n,a,b,c,d;
    cin>>t;
    while(t--)
    {

        cin>>n>>a>>b>>c>>d;
        memset(coun,0,sizeof(coun));
        ll s=d;
        coun[s]++;
        for(int i=1;i<=n-1;i++)
        {
            s = (1LL*a*s*s + 1LL*b*s + c)%mod;
            coun[s]++;

        }
        ll now=0,res=0;
        for(int i=0;i<RANGE;i++)
        {
            if(now&1) res-=(coun[i]&1)*i;
            else res += (coun[i]&1)*i;
            now += coun[i];
        }
        if(res<0)res=-res;
        printf("%lld\n",res);
    }
    return 0;
}
