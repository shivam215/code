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
int solve(int n)
{
    int res=1;
    int cnt=0;
    while(n%2==0)
    {
        cnt++;
        n/=2;
    }
    res = max(res,cnt);
    for(int i=3;1LL*i*i<=n;i+=2)
    {
        int cnt=0;
        while(n%i==0)
        {
            cnt++;
            n/=i;
        }
        res=max(res,cnt);
    }
    return res;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int res = solve(n);
        printf("%d\n",res);
    }
    return 0;
}
