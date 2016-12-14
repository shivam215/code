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
int n,m;
struct matrix
{
    ll data[31][31];
    matrix()
    {
        memset(data,0,sizeof data);
    }
};
matrix mul(matrix a,matrix b)
{
    matrix c;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
            for(int k=0;k<m;k++)
            {
                c.data[i][j]  = (c.data[i][j] + a.data[i][k]*b.data[k][j])%mod;
            }
        }
    }
    return c;
}
matrix power(matrix a,int k)
{
    if(k==1)return a;
    matrix b = power(a,k/2);
    matrix c = mul(b,b);
    if(k&1)c = mul(c,a);
    return c;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        if(n==1)
        {
            cout<<m<<"\n";
            continue;
        }
        matrix even,odd;
        for(int i=0;i<m;i++)
        {
            for(int j=i-1;j<=i+1;j++)
            {
                if(j>=0&&j<m)
                {
                    even.data[i][j]=1;
                    if(j!=i)odd.data[i][j]=1;
                }
            }
        }
        matrix ans;
        if(n==2)ans = odd;
        else
        {
            matrix c = power(odd,(n-1)/2);
            matrix d = power(even,(n-1)/2);
            ans = mul(c,d);
            if(!(n&1))ans = mul(ans,odd);
        }
        ll res=0;
        rep(i,0,m)rep(j,0,m)res = (res + ans.data[i][j])%mod;
        cout<<res<<"\n";
    }
    return 0;

}
