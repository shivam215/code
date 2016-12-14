#include <bits/stdc++.h>
#define inf 100000000
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
using namespace std;
map<pii,int> ma;
int main()
{
    int t;
    scano(t);
    while(t--)
    {
        int n,p,q;
        scant(n,p);
        ma.clear();
        rep(i,0,n-1)
        {
            int a,b;
            scant(a,b);
            ma[mp(a,b)]=1;
            ma[mp(b,a)]=1;
        }
        scano(q);
        int flag=0;
        rep(i,0,n-1)
        {
            int a,b;
            scant(a,b);
            if(!ma[mp(a,b)])flag=1;
        }
        if(flag)puts("0");
        else puts("1");
    }
    return 0;
}
