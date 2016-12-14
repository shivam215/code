#include <bits/stdc++.h>
#define inf 10000000000LL
#define B 400
#define scanint(x) scanf("%d",&x)
#define scanll(x) scanf("%lld",&x)
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
ll a[1000006],b[400],ans[1000006];
int main()
{
    int t,n,q;
    scanint(t);
    for(int test=1;test<=t;test++)
    {
        scanint(n);
        scanint(q);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            b[i/B] = min(b[i/B],a[i]);
        }


        for(int query=1;query<=q;query++)
        {
            int l,r;
            scanint(l);
            scanint(r);
            l--;r--;
            int p = l/B;
        int q = r/B;
        ll mn=inf;
        if(p==q)
        {
            for(int i=l;i<=r;i++)
            {
                mn = min(mn,a[i]);
            }
        }
        else
        {
            for(int i=l;i<=(p+1)*B-1;i++)
            {
                mn = min(mn,a[i]);
            }
            for(int i=p+1;i<q;i++)
            {
                mn = min(mn,b[i]);
            }
            for(int i=q*B;i<=r;i++)
            {
                mn = min(mn,a[i]);
            }
        }
        ans[query]=mn;
        }
        printf("Scenario #%d:\n",test);
        printf("\n");
        for(int i=1;i<=q;i++)printf("%lld\n",ans[i]);



    }
    return 0;
}
