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
int mark[1000],ans[1000];
vector< pair<int,pii> > v;
int main()
{
    int n;
    cin>>n;
    for(int i=2;i<=2*n;i++)
    {
        for(int j=1;j<i;j++)
        {
            int temp;
            cin>>temp;
            v.pb(mp(temp,mp(i,j)));
        }
    }
    sort(v.begin(),v.end());
    for(int i=v.size()-1;i>=0;i--)
    {
        int p = v[i].se.fe;
        int q = v[i].se.se;
        if(!mark[p]&&!mark[q])
        {
            ans[p]=q;
            ans[q]=p;
            mark[p]=1;mark[q]=1;
        }
    }
    for(int i=1;i<=2*n;i++)
    {
        cout<<ans[i]<<' ';
    }
    cout<<endl;
    return 0;
}
