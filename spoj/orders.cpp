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
vector<pii > v;
int a[200005],ans[200005];
void update(int x,int val)
{
    for(int i=x;i<=n;)
    {
        tree[x]+=val;
        i += i&(-i);
    }
}
int get(int x)
{
    int res=0;
    for(int i=x;i>=1;)
    {
        res = res + tree[i];
        i-=i&(-i);
    }
    return res;
}
int main()
{
    int t;
    scano(t);
    while(t--)
    {
        int n;
        scano(n);
        for(int i=1;i<=n;i++)scano(a[i]);
        for(int i=1;i<=n;i++)tree[i]=i;
        for(int i=1;i<=n;i++)
        {
            if(a[i]!=0)
            {
                int pos = get(i)-get(i-1);
                int diff = i-a[i]-pos;

                update(i,diff);
                update(i+1,-diff);

            }
        }

    }
    return 0;
}
