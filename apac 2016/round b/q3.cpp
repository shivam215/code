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
map<ll,int> m;
int prime[MAX+5];
void seive()
{
    for(int i=0;i<MAX+5;i++)prime[i]=1;
    for(ll i=2;i<=MAX;i++)
    {
        if(prime[i])
        {
            for(ll j=i*i;j<=MAX;j+=i)
            {
                prime[j]=0;
            }
        }
    }
}
int sum(ll x)
{
    int res=0;
    while(x>0)
    {
        res = res + (x%10);
        x/=10;
    }
    return res;
}
int isg(ll x)
{
    if(prime[sum(x)]==1)return 1;
    else return 0;
}
int tell(ll x)
{
    if(m.find(x)!=m.end())return m[x];
    if(isg(x))
    {
        return m[x]=0;
    }
    ll temp = x;
    ll tem = x;
    if(temp%2==0)
    {
    while((temp%2)==0)
    {
        temp/=2;
        tem/=2;
    }
    if(!tell(temp))return m[x]=1;
    }
    for(ll i=3;i*i<=x;i+=2)
    {
        if(prime[i])
        {

        temp = x;
        if((temp%i)==0)
        {
        while((temp%i)==0)
        {
            temp/=i;
            tem/=i;
        }
        if(!tell(temp))return m[x]=1;
        }
        }

    }
    if(tem>1&&(!tell(x/tem)))return m[x]=1;
    return m[x]=0;
}

int main()
{
    //freopen("q3l.in","r",stdin);
    //freopen("q3l.out","w",stdout);
    int t;
    scano(t);
    seive();
    //for(int i=0;i<100;i++)cout<<prime[i]<<endl;
    rep(test,1,t+1)
    {
        ll n;
        scanll(n);
        m.clear();
        int res = tell(n);
        if(res==0)printf("Case #%d: Seymour\n",test);
        else printf("Case #%d: Laurence\n",test);
    }
    return 0;
}


