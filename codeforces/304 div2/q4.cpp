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
#define MAX 5000006
using namespace std;
int prime[MAX],fac[MAX],calc[MAX];
void sieve()
{
    for(int i=2;i<MAX;i++)prime[i]=1;
    for(ll i=2;i<MAX;i++)
    {
        for(ll j=i*i;j<MAX;j+=i)
        {
            prime[j]=0;
        }
    }
    for(int i=2;i<MAX;i++)
    {
        if(prime[i])
        {
            for(int j=i;j<MAX;j+=i)
            {
                fac[j]=i;
            }
        }
    }
    calc[1]=0;
    for(int i=2;i<MAX;i++)
    {
        calc[i] = calc[i/fac[i]] + 1;
    }
    for(int i=2;i<MAX;i++)
    {
        calc[i] = calc[i-1]+calc[i];
    }
}
int main()
{
    int t;
    scano(t);
    sieve();
    while(t--)
    {
        int a,b;
        scant(a,b);
        int res = calc[a] - calc[b];
        printf("%d\n",res);
    }
    return 0;
}
