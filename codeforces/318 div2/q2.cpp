#include <bits/stdc++.h>
#define scanint(x) scanf("%d",&x)
#define scanll(x) scanf("%lld",&x)
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int cnt[4004],g[4004][4004];
vector< pii > e;
int main()
{
    int n,m,a,b,c;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {   cin>>a>>b;
        e.push_back(mp(a,b));
        cnt[a]++;
        cnt[b]++;
        g[a][b]=1;
        g[b][a]=1;
    }
    int ans = INT_MAX;
    for(int i=0;i<e.size();i++)
    {
        a = e[i].first;
        b = e[i].second;
        for(int j=1;j<=n;j++)
        {
            if(j==a||j==b)continue;
            int c = j;
            if(g[a][b]&&g[b][c]&&g[a][c])
            {
            int temp = cnt[a]+cnt[b]+cnt[c]-6;
            ans = min(ans,temp);
            }
        }
    }
    if(ans==INT_MAX) printf("-1\n");
    else printf("%d\n",ans);
    return 0;
}
