#include <bits/stdc++.h>
#define inf 100000000
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


ll fib[5000010];
ll csfib[5000010];
ll s[5000010];
ll cs[5000010];

int n=5000010,m;

void solve()
{
    fib[1]=1;
    fib[2]=1;
    rep(i,3,n)
    fib[i]=(fib[i-1]+fib[i-2])%mod;

    csfib[1]=1;
    csfib[2]=2;
    rep(i,3,n)
    csfib[i]=(csfib[i-1]+fib[i])%mod;

    ll res=0;
    s[1]=0;
    rep(i,2,n)
    {
        s[i]=(s[i-1]+(fib[i]*csfib[i-1])%mod)%mod;

    }
    cs[1]=s[1];
    rep(i,2,n)
    {
        cs[i]=(cs[i-1]+s[i])%mod;

    }
}

int main()
{

    int a,b;
    solve();
    int output1;
    int t;
    cin>>t;
    while(t--)
    {
        scant(a,b);
        output1=(cs[b]-cs[a-1])%mod;
        while(output1<0)
        {
           output1=(output1+mod)%mod;
        }

        cout<<output1<<endl;
    }
    return 0;
}
