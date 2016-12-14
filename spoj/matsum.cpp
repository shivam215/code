#include <bits/stdc++.h>
#define inf 100000000
#define scano(x) scanf("%d",&x)
#define scanll(x) scanf("%lld",&x)
#define scant(x,y) scanf("%d%d",&x,&y)
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector<ll>
#define pii pair<ll,ll>
#define vpii vector< pii >
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define fe first
#define se second
using namespace std;
int n,tree[1100][1100];
void update(int x,int y,int val)
{
    while(x<=n)
    {
        int y1 = y;
        while(y1<=n)
        {
            tree[x][y1]+=val;
            y1+=(y1&-y1);
        }
        x+=(x&-x);
    }
}
int read(int x,int y)
{
    int sum=0;
    while(x)
    {
        int y1 = y;
        while(y1)
        {
            sum += tree[x][y1];
            y1-=(y1&-y1);
        }
        x-=(x&-x);
    }
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        memset(tree,0,sizeof(tree));
        while(1)
        {
            int a,b,c,d;
            string s;
            cin>>s;
        if(s=="SET")
        {
            cin>>a>>b>>c;
            a++;b++;
            int pval = read(a,b)-read(a-1,b)-read(a,b-1)+read(a-1,b-1);
            update(a,b,c-pval);
        }
        else if(s=="SUM")
        {
            cin>>a>>b>>c>>d;
            a++;b++;c++;d++;
            int res = read(c,d)-read(a-1,d)-read(c,b-1)+read(a-1,b-1);
            printf("%d\n",res);
        }
        else break;
        }
    }
    return 0;

}
