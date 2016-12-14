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
#define MAX 1000000
using namespace std;
ll phi[MAX+5],ans[MAX+5];
void solve()
{
    for(int i=1;i<=MAX;i++)phi[i]=i;
    for(int i=2;i<=MAX;i++)
    {
        if(phi[i]==i)
        {
            for(int j=i;j<=MAX;j+=i)
            {
                phi[j]/=i;
                phi[j]*=(i-1);
            }
        }
    }
    memset(ans,0,sizeof(ans));
    for(int i=1;i<=MAX;i++)
    {
        for(int j=i;j<=MAX;j+=i)
        {
            ans[j] += phi[i]*i;
        }
    }
}
int main()
{
    int t;
    cin>>t;
    solve();
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        ll res1 = ((ans[b] + 1)*b)/2;
        ll res2 = ((ans[a-1]+1)*(a-1))/2;
        ll res = res1-res2;
        cout<<res<<endl;
    }
    return 0;
}
