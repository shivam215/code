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
int num[401],ch[100005];
double ans[401][100005];
int main()
{
    freopen("q2s.in","r",stdin);
    freopen("q2s.out","w",stdout);
    num[1]=1;
    for(int i=2;i<401;i++)
    {
        num[i] = num[i-1] + i;
    }
    for(int i=1;i<401;i++)
    {
        int temp = (i*(i-1))/2 +1;
        for(int j=temp;j<=temp+i-1;j++)
        {
            ch[j] = j + i;
        }
    }
    int t;
    cin>>t;
    rep(test,1,t+1)
    {
        int b,l,n;
        cin>>b>>l>>n;
        memset(ans,0,sizeof(ans));
        ans[1][1] = 750*b;
        int lev=1,ok=1;
        while(ok)
        {
            ok=0;
            for(int i=1;i<=num[lev];i++)
            {
                if(ans[lev][i]>250)
                {
                    double temp = ans[lev][i]-250;
                    ans[lev][i]=250;
                    ans[lev+1][i]+=(temp/3);
                    ans[lev+1][ch[i]] += (temp/3);
                    ans[lev+1][ch[i]+1] += (temp/3);
                    ok=1;
                }
            }
            lev++;
        }
        printf("Case #%d: %.7f\n",test,ans[l][n]);
    }
    return 0;
}
