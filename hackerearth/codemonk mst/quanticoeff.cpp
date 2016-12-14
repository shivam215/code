#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
#define mp make_pair
#define pb push_back
using namespace std;
int parent[5005],ran[5005];
vector< pair<int,pair<int,int> > > edge;
int Find(int i)
{
    if (parent[i]!=i)
        parent[i] = Find(parent[i]);
    return parent[i];
}
void Union(int x, int y)
{
    int xroot = Find(x);
    int yroot = Find(y);
    if (ran[xroot]<ran[yroot])
        parent[xroot] = yroot;
    else if (ran[xroot]>ran[yroot])
        parent[yroot] = xroot;
    else
    {
        parent[yroot]=xroot;
        ran[xroot]++;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t,i,a,b,c,n,m,coun;
    ll res;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        edge.clear();
        for(i=0;i<m;i++)
        {
            cin>>a>>b>>c;
            edge.pb(mp(c,mp(a,b)));
        }
        sort(edge.begin(),edge.end());
        //for(i=0;i<m;i++)cout<<edge[i].first<<' '<<edge[i].second.first<<' '<<edge[i].second.second<<endl;
        for(i=0;i<5005;i++)parent[i]=i;
        memset(ran,0,sizeof(ran));
        i=0;
        coun=1;res=1;
        while(coun<=n-1)
        {
            int cost = edge[i].first;
            int src = edge[i].second.first;
            int dest = edge[i].second.second;
            int x = Find(src);
            int y = Find(dest);
            if(x!=y)
            {
                res = (res*cost)%mod;
                coun++;
                Union(x,y);
            }
            i++;
        }
        printf("%lld\n",res);
    }
    return 0;
}

