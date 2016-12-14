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
string a[1003],b[1003];
int main()
{
    int n;
    scano(n);
    rep(i,0,n)cin>>a[i];
    rep(i,0,n)cin>>b[i];
    int cnt=0;
    for(int i=0;i<=n-4;i++)
    {
        for(int j=0;j<=n-4;j++)
        {
            if(a[i][j]!=b[i][j])
            {
                cnt++;
                for(int k=i;k<i+4;k++)
                {
                    for(int l=j;l<j+4;l++)
                    {
                        if(a[k][l]=='H')a[k][l]='T';
                        else a[k][l]='H';
                    }
                }
            }
        }
    }
    int flag=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i][j]!=b[i][j])
            {
                flag=1;
                break;
            }
        }
        if(flag)break;
    }
    if(flag)printf("-1\n");
    else printf("%d\n",cnt);
    return 0;
}
