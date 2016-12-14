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
        int n;
        scano(n);
        int flag=0;
        for(int i=1;i<n;i++)
        {
            int x = sqrt(1LL*n*n-1LL*i*i);
            if(1LL*x*x==1LL*n*n-1LL*i*i)
            {
                flag=1;break;
            }
        }
        if(flag)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
