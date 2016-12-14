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
#define piii pair<int,pair<int,int> >
#define piiiii pair<int,pair<pii,pii > >
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fe first
#define se second
#define max_x 1004
#define max_y 1004
using namespace std;
int tree[1004][1004];
int ans[100005],n;
vector<piiiii > query;
vector<piii > v;
void update(int x , int y , int val)
{
    int y1;
    while (x < max_x)
    {
        y1 = y;
        while (y1 < max_y)
        {
            tree[x][y1] += val;
            y1 += (y1 & -y1);
        }
        x += (x & -x);
    }
}
int read(int x,int y)
{
    int sum= 0;
    while(x)
    {
        int y1 = y;
        while(y1)
        {
            sum += tree[x][y1];
            y1 -= y1 & -y1;
        }
        x -= x & -x;
    }
    return sum;
}
piii mpa(int x,int y,int z)
{
    return mp(x,mp(y,z));
}
piiiii mpaa(int a,int b,int c,int d,int e)
{
    return mp(a,mp(mp(b,c),mp(d,e)));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin>>n>>q;
    for(int i=1; i<=n; i++)
    {
        int a,b;
        cin>>a>>b;
        v.pb(mpa(a,i,b));
    }
    sort(v.begin(),v.end());
    for(int i=1; i<=q; i++)
    {
        int a,b,x,y;
        cin>>a>>b>>x>>y;
        x++;y++;
        query.pb(mpaa(a,i,b,x,y));
    }
    sort(query.begin(),query.end());
    for(int i=0; i<v.size(); i++)
    {
        int a = v[i].fe;
        int j = v[i].se.fe;
        int b = v[i].se.se;
        update(b,j,1);
    }
    int k=0;
    for(int i=0; i<query.size(); i++)
    {
        int a = query[i].fe;
        int j = query[i].se.fe.fe;
        int b = query[i].se.fe.se;
        int x = query[i].se.se.fe;
        int y = query[i].se.se.se;
        while(k<n&&v[k].fe<a)
        {
            update(v[k].se.se,v[k].se.fe,-1);
            k++;
        }
        ans[j] = read(b,y)-read(b,x-1);
    }
    for(int i=1; i<=q; i++)
    {
        printf("%d\n",ans[i]);
    }
    return 0;

}
