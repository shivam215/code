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
#define MAX 100000
using namespace std;
int prime[MAX+5],ans[MAX+5];
void sieve()
{
    rep(i,0,MAX+5)prime[i]=1;
    for(int i=2;i<=MAX;i++)
    {
        if(prime[i])
        {
            for(ll j=1LL*i*i;j<=MAX;j+=i)
            {
                prime[j]=0;
            }
        }
    }
}
void solve()
{
    for(int i=2;i<=MAX;i++)
    {
        if(prime[i])
        {
            for(int j=i;j<=MAX;j+=i)
            {
                ans[j]++;
            }
        }
    }
}
int main()
{
    sieve();
    solve();
    int t;
    cin>>t;
    while(t--)
    {
        int n,i;
        cin>>n;
        int cnt=0;
        for(i=2;i<=MAX;i++)
        {
            if(ans[i]>=3)
            {
                cnt++;
                if(cnt==n)break;
            }
        }
        cout<<i<<endl;
    }
    return 0;

}
