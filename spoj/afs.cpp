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
#define MAX 1000006
using namespace std;
ll a[MAX];
void fin()
{
    for(int i=1;i<MAX;i++)
    {
        for(int j=2*i;j<MAX;j+=i)
        {
            a[j] = a[j] + i;
        }
    }
}
int main()
{
    int t;
    scano(t);
    fin();
    while(t--)
    {
        int n;
        scano(n);
        ll res=0;
        for(int i=2;i<=n;i++)
        {
            res = res + a[i];
        }
        printf("%lld\n",res);
    }
}

