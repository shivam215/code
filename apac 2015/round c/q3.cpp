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
int dp[1000006],mark[10];
int rec(int x)
{
    if(dp[x]<inf)return dp[x];
    int res = inf;
    for(int i=2;i*i<=x;i++)
    {
        if(x%i!=0)continue;
        res = min(res,rec(i)+rec(x/i)+1);
    }
    return dp[x]=res;
}
int check(int x)
{
    int res=0;
    while(x>0)
    {
        if(!mark[x%10])
        {
            return -1;
        }
        res++;
        x/=10;

    }
    return res;
}
int main()
{
    freopen("q3l.in","r",stdin);
    freopen("q3l.out","w",stdout);
    int t;
    cin>>t;
    rep(test,1,t+1)
    {
        rep(i,0,10)
        {
            cin>>mark[i];
        }
        int x,res;
        cin>>x;
        for(int i=0;i<=x;i++)
        {
            res = check(i);
            if(res==-1)dp[i]=inf;
            else dp[i]=res;
        }
        printf("Case #%d: ",test);
        res = rec(x);
        if(res>=inf)cout<<"Impossible"<<endl;
        else cout<<res+1<<endl;
    }
    return 0;
}

