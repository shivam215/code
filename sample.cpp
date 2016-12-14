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
#define MAX 100005
using namespace std;
int a[MAX],b[MAX],f[MAX];
vector<int> g[MAX];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>f[i];
        g[f[i]].pb(i);
    }
    for(int i=1;i<=m;i++)
    {
        cin>>b[i];
    }
    int flag=0,amb=0;
    for(int i=1;i<=m;i++)
    {
        if(g[b[i]].size()>1)
        {
            amb=1;
        }
        if(g[b[i]].size()==0)
        {
            flag=1;
            break;
        }
        a[i] = g[b[i]][0];
    }
    if(flag==1)
    {
        printf("Impossible\n");
    }
    else if(flag==0)
    {
        if(amb==1)printf("Ambiguity\n");
        else
        {
            printf("Possible\n");
            for(int i=1; i<=m; i++)
            {
                printf("%d ",a[i]);
            }
            printf("\n");

        }
    }
    return 0;
}
