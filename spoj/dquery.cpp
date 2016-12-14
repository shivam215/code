#include <bits/stdc++.h>
#define scano(x) scanf("%d",&x)
#define scant(x,y) scanf("%d%d",&x,&y)
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int t[30004],n,ans[200005],a[30004],lastpos[1000006];
vector<int> v[30004];
vector< pii > query;
void upd(int i, int x)
{
    for(;i<=n;i += i & -i)
    {
        t[i] += x;
    }

}
int get(int i)
{
    int s = 0;
    for (; i; i -= i & -i) s += t[i];
    return s;
}
int main()
{
    int q;
    scano(n);
    rep(i,1,n+1)scano(a[i]);
    scano(q);
    rep(i,0,q)
    {
        int a,b;
        scant(a,b);
        query.push_back(mp(a,b));
        v[b].push_back(i);
    }
    rep(i,1,n+1)upd(i,1);
    memset(lastpos,-1,sizeof(lastpos));
    rep(i,1,n+1)
    {
        if(lastpos[a[i]]!=-1)
        {
            upd(lastpos[a[i]],-1);
        }
        lastpos[a[i]]=i;
        rep(j,0,v[i].size())
        {
            int in = v[i][j];
            int l = query[in].first;
            int r = query[in].second;
            ans[in] = get(r)-get(l-1);
        }
    }
    for(int i=0;i<q;i++)
    {
        printf("%d\n",ans[i]);
    }
    return 0;
}
