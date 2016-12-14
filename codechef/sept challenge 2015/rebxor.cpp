#include <bits/stdc++.h>
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
using namespace std;
int a[400005],ans1[400005],ans2[400005];
int trie[2][10000000];
void insert_trie(int xr)
{
    static int cnt=1;
    int cur=0;
    int k=0;
    for(int i=30;i>=0;i--)
    {
        int temp = (xr>>i)&1;
        if(trie[temp][cur]!=0)
        {
            cur = trie[temp][cur];
        }
        else
        {
            trie[temp][cur]=cnt;
            cur = cnt;
            cnt++;
        }
    }
}
int query(int xr)
{
    int cur=0;
    int res=0;
    for(int k=30;k>=0;k--)
    {
        int temp = (xr>>k)&1;
    if(trie[temp^1][cur]!=0)
    {
        cur = trie[temp^1][cur];
        res = res + (temp^1)*(1LL<<k);
    }
    else
    {
        cur = trie[temp][cur];
        res = res + (temp)*(1LL<<k);
    }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    scano(n);
    rep(i,0,n)scano(a[i]);
    int xr=0;
    rep(i,0,n)
    {
        xr = xr^a[i];
        insert_trie(xr);
        int y = query(xr);
        ans1[i]=xr;
        if(ans1[i]<(xr^y))ans1[i]=xr^y;
        if(i!=0)
        {if(ans1[i]<ans1[i-1])ans1[i]=ans1[i-1];}
    }
    memset(trie,0,sizeof(trie));
    xr=0;
    for(int i=n-1;i>=0;i--)
    {
        xr = xr^a[i];
        insert_trie(xr);
        int y = query(xr);
        ans2[i]=xr;
        if(ans2[i]<(xr^y))ans2[i]=xr^y;
        if(i!=n-1){if(ans2[i]<ans2[i+1])ans2[i]=ans2[i+1];}
    }
    int res=0;
    for(int i=0;i<n-1;i++)
    {
        if(res<ans1[i]+ans2[i+1])res=ans1[i]+ans2[i+1];
    }
    printf("%d\n",res);
    return 0;


}
