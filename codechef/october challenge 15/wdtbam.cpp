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
int cost[1003];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        string a,b;
        cin>>n;
        cin>>a>>b;
        rep(i,0,n+1)cin>>cost[i];
        int eq=0,neq=0;
        int ans=0;
        rep(i,0,n)
        {
            if(a[i]==b[i])eq++;
            else neq=1;
        }
        if(neq==0)ans=cost[n];
        else
        {
            rep(i,0,eq+1)ans=max(ans,cost[i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
