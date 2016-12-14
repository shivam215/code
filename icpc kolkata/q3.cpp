#include <bits/stdc++.h>
#define inf 1000000000
#define mod 1000000007
#define scano(x) scanf("%d",&x)
#define scanll(x) scanf("%lld",&x)
#define scant(x,y) scanf("%d%d",&x,&y)
#define pb push_back
#define mp make_pair
#define ll long long int
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fe first
#define se second
using namespace std;
int arr[100005],dp[100005],n;
void reset()
{
    for(int j=1;j<=n;j++)dp[j]=0;
}
int main()
{
    int q,a,b;
    vector<pair<int,int> > v;
    scant(n,q);
    int sn = sqrt(n);
    rep(i,0,q)
    {
        cin>>a>>b;
        v.pb(mp(a,b));
    }
    sort(v.begin(),v.end());
    int prev;
    rep(i,0,v.size())
    {
        a = v[i].fe;
        b = v[i].se;
        if(a>sn)
        {
            if(prev<=sn)
            {
                for(int j=1; j<=n; j++)
                {
                    if(j-prev>=1)
                    {
                        dp[j] += dp[j-prev];
                    }
                    arr[j]+=dp[j];
                }

            }
            for(int j=b;j<=n;j+=a)
            {
                arr[j]++;
            }
            prev=a;
        }
        else
        {
            if(i!=0)
            {
                if(a!=prev)
                {
                    for(int j=1;j<=n;j++)
                    {
                        if(j-prev>=1)
                        {
                            dp[j] += dp[j-prev];
                        }
                        arr[j] += dp[j];
                    }
                    reset();
                }
            }
            prev=a;
            dp[b]++;
        }
    }
    if(prev<=sn)
    {
        for(int j=1; j<=n; j++)
        {
            if(j-prev>=1)
            {
                dp[j] = dp[j] + dp[j-prev];

            }
            arr[j] += dp[j];
        }
    }
    rep(i,1,n+1)printf("%d ",arr[i]);
    printf("\n");
    return 0;
}
