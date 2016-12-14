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
int x[100],y[100];
vector<int> ans;
int main()
{
    int n;
    cin>>n;
    rep(i,0,n*n)
    {
        int a,b;
        cin>>a>>b;
        if(x[a]!=1&&y[b]!=1)
        {
            x[a]=1;y[b]=1;
            ans.pb(i+1);
        }
    }
    rep(i,0,ans.size())printf("%d ",ans[i]);
    printf("\n");
    return 0;
}
