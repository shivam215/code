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
int a[1003][1003],lef[1003][1003],righ[1003][1003],top[1003][1003],bot[1003][1003];
int main()
{
    int t;
    scano(t);
    while(t--)
    {
        int n,m;
        scant(n,m);
        rep(i,0,n)rep(j,0,m)scano(a[i][j]);
        rep(i,0,n)
        {
            rep(j,0,m)
            {
                if(j==0)lef[i][j]=a[i][j];
                else lef[i][j] = min(a[i][j],lef[i][j-1]+a[i][j]);
            }
        }
        rep(i,0,n)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(j==m-1)righ[i][j]=a[i][j];
                else righ[i][j] = min(a[i][j],righ[i][j+1]+a[i][j]);
            }
        }
        rep(j,0,m)
        {
            rep(i,0,n)
            {
                if(i==0)top[i][j]=a[i][j];
                else top[i][j] = min(a[i][j],top[i-1][j]+a[i][j]);
            }
        }
        rep(j,0,m)
        {
            for(int i=n-1;i>=0;i--)
            {
                if(i==n-1)bot[i][j]=a[i][j];
                else bot[i][j] = min(a[i][j],bot[i+1][j]+a[i][j]);
            }
        }
        int ans = inf;
        rep(i,0,n)
        {
            rep(j,0,m)
            {
                ans = min(ans,lef[i][j]+righ[i][j]+top[i][j]+bot[i][j]-3*a[i][j]);
            }
        }
        printf("%d\n",ans);
    }
}
