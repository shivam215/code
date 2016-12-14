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
#define MAX 31622777
using namespace std;
int a[505][505],row[505];
int main()
{
    int n,m,q;
    scant(n,m);
    scano(q);
    rep(i,0,n)rep(j,0,m)scano(a[i][j]);
    rep(i,0,n)
    {
        int cur=0,ans=0;
        rep(j,0,m)
        {
            if(a[i][j]==1)cur++;
            else cur=0;
            ans = max(ans,cur);
        }
        row[i]=ans;
    }
    while(q--)
    {
        int c,d;
        scant(c,d);
        c--;d--;
        a[c][d]=1-a[c][d];
        int cur=0,ans=0;
        for(int j=0;j<m;j++)
        {
            if(a[c][j]==1)cur++;
            else cur=0;
            ans = max(ans,cur);
        }
        row[c]=ans;
        ans=0;
        for(int i=0;i<n;i++)ans=max(ans,row[i]);
        cout<<ans<<endl;
    }
    return 0;

}

