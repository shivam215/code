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
int main()
{
    int t;
    scano(t);
    while(t--)
    {
        int a,b;
        scant(a,b);
        ll res=0;
        for(int i=a;i<=b;i++)
        {
            res = (res + (1LL*i*b)/__gcd(i,b));
            if(res>=mod)res%=mod;

        }
        printf("%lld\n",res);
    }
    return 0;
}
