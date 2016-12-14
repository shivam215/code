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
#define B 320
using namespace std;
int a[100005],n,l,k;
ll b[320][100005];
int main()
{
    int q;
    scant(n,q);
    rep(i,0,n)scano(a[i]);
    rep(i,0,n)b[i/B][a[i]]++;
    rep(i,0,B)
    {
        for(int j=100002;j>=0;j--)
        {
            b[i][j] = b[i][j] + b[i][j+1];
        }
    }
    while(q--)
    {
        scant(l,k);
        int i,j;
        for(i=0;i<B;i++)
        {
            if(b[i][l]<k)k=k-b[i][l];
            else
            {
                break;
            }
        }
        for(j=i*B;j<(i+1)*B;j++)
        {
            if(a[j]>=l)k--;
            if(k==0)
            {
                break;
            }
        }
        printf("%d\n",a[j]);
    }
    return 0;
}
