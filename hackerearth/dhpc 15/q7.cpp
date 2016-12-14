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
int n;
struct matrix
{
    ll data[55][55];
    matrix()
    {
        memset(data,0,sizeof data);
    }
};
matrix mul(matrix a,matrix b)
{
    matrix c;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=n;k++)
            {
                c.data[i][j]  = (c.data[i][j] + a.data[i][k]*b.data[k][j])%mod;
            }
        }
    }
    return c;
}
matrix power(matrix a,int k)
{
    if(k==1||k==0)return a;
    matrix b = power(a,k/2);
    matrix c = mul(b,b);
    if(k&1)c = mul(c,a);
    return c;
}
int main()
{
    int m,p;
    cin>>n>>m>>p;
    struct matrix g;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        g.data[a][b]=1;
        g.data[b][a]=1;
    }
    matrix ans = power(g,p);
    int q;
    cin>>q;
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        if(p==0)
        {
            if(x!=y)printf("0\n");
            else printf("1\n");
        }
        else printf("%lld\n",ans.data[x][y]);
    }
    return 0;
}
