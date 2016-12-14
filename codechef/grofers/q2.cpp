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
ll a[100005],n,m;
int check(ll mid)
{
    ll temp=0;
    int i=0,cnt=0;
    for(int j=0;j<n;j++)
    {
        if(a[j]>mid)
        {
            return 0;
        }
    }
    while(i<n)
    {
        while(temp<mid&&i<n)
        {
            temp = temp + a[i];
            i++;
        }
        cnt++;
        if(temp>mid)i--;
        temp=0;
    }
    if(cnt<=m)return 1;
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin>>n>>m;
    ll sum=0;
    rep(i,0,n)cin>>a[i],sum+=a[i];
    ll low=0,high=sum;
    while(low<high)
    {
        ll mid = (low+high)/2;
        int chk = check(mid);
        if(chk==1)high=mid;
        else low=mid+1;
    }
    printf("%lld\n",high);
    return 0;
}
