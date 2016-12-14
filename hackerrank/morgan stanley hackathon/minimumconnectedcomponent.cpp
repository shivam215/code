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
using namespace std;
int parent[200005],ran[200005],wt[200005];
set< pii > s;
int fin(int i)
{
    if(parent[i]==i)return i;
    return parent[i]=fin(parent[i]);
}
void unio(int i,int j)
{
    int x = fin(i);
    int y = fin(j);
    if(x==y)return;
    s.erase(mp(wt[x],x));
    s.erase(mp(wt[y],y));
    if(ran[x]>ran[y])
    {
        parent[y]=x;
        wt[x]+=wt[y];
        s.insert(mp(wt[x],x));
    }
    else if(ran[x]<ran[y])
    {
        parent[x]=y;
        wt[y]+=wt[x];
        s.insert(mp(wt[y],y));
    }
    else
    {
        parent[y]=x;
        wt[x]+=wt[y];
        ran[x]++;
        s.insert(mp(wt[x],x));
    }
}
int main()
{
    int n,q;
    cin>>n>>q;
    rep(i,1,n+1)cin>>wt[i];
    rep(i,1,n+1)parent[i]=i;
    rep(i,1,n+1)ran[i]=0;
    rep(i,1,n+1)s.insert(mp(wt[i],i));
    while(q--)
    {
        int u,v;
        cin>>u>>v;
        unio(u,v);
        set< pii >::iterator it;
        it = s.begin();
        cout<<(*it).fe<<endl;
    }
    return 0;
}
