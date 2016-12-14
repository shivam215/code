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
#define MAX 10000008
using namespace std;
int dp[102][10004],n,m,q,w[1003],p[102],h[102];
int rec(int i,int j)
{
    if(i==n)
    {
        if(j<=q)return -inf;
        return inf;
    }
    if(dp[i][j]!=-1)return dp[i][j];
    int res=inf;
    if(p[i]==0)res = max(0,rec(i+1,j));
    else if(p[i]>0)
    {
        for(int k=0;k<m;k++)
        {
            if(w[k]<0)
            {
                int temp = j + abs(k-h[i]);
                int q = p[i]/abs(w[k]);
                int rem = p[i]%(abs(w[k]));
                int temp1 = q + (rem!=0);
                if(temp<=q)
                {
                    int res1 = rec(i+1,temp);
                    if(res1!=inf)res = min(res,max(temp1,res1));
                }
            }
        }
    }
    else
    {
        for(int k=0;k<m;k++)
        {
            if(w[k]>0)
            {
                int temp = j + abs(k-h[i]);
                int q = (abs(p[i]))/w[k];
                int rem = (abs(p[i]))%w[k];
                int temp1 = q + (rem!=0);
                if(temp<=q)
                {
                    int res1 = rec(i+1,temp);
                    if(res1!=inf)res = min(res,max(temp1,res1));
                }
            }
        }

    }
    return dp[i][j]=res;
}
int main()
{
    //freopen("q2.in","r",stdin);
    //freopen("q2.out","w",stdout);
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    rep(test,1,t+1)
    {
        cin>>n>>m>>q;
        rep(i,0,m)cin>>w[i];
        rep(i,0,n)
        {
            cin>>p[i]>>h[i];
        }
        rep(i,0,n)rep(j,0,q+1)dp[i][j]=-1;
        int res = rec(0,0);
        printf("Case #%d: ",test);
        if(res>=inf)printf("IMPOSSIBLE\n");
        else printf("%d\n",res);
    }
    return 0;
}

