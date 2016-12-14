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
vector< pii > point;
int n,a[100005],m;
int cum[100005],len[100005],dp[100005];
int main()
{
    scano(n);
    rep(i,0,n)scano(a[i]);
    cum[0]=a[0];
    rep(i,1,n)cum[i] = cum[i-1]+a[i];
    scano(m);
    rep(i,0,m)
    {
        int a,b;
        scant(a,b);
        a--;
        len[a]=b;
    }
    int pre=-1;
    for(int i=0;i<n;i++)
    {
        if(len[i]!=0)
        {
            int j = min(n-1,pre+len[i]);
            int k = j-len[i]+1;
            pre=j;
            int sum = cum[j];
            if(k-1>=0)sum-=cum[k-1];
            dp[j] = sum;
            for(int f=j+1;f<n&&f<i+len[i];f++)
            {
                k = f-len[i]+1;
                if(k<0)
                {
                    dp[f]=dp[f-1];
                    continue;
                }
                if(k==0)
                {
                    sum = cum[j];
                    dp[f] = max(dp[f-1],sum);
                }
                else
                {
                    sum = cum[f]-cum[k-1];
                    dp[f] = max(dp[f-1],sum+dp[k-1]);
                }

            }
        }
        else
        {
            if(i-1>=0)dp[i]=max(dp[i],dp[i-1]);
        }

    }
    cout<<dp[n-1]<<endl;
    return 0;

}
