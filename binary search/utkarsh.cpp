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
    	temp = 0;
        while(i<n&&temp+a[i]<=mid)
        {
            temp = temp + a[i];
            i++;
        }
        cnt++;
    }
    if(cnt<=m)return 1;
    return 0;
}
ll bin(ll i,ll j){
	if(i==j){
		return i;
	}
	ll mid = (i+j)/2;
	if(check(mid))
		return bin(i,mid);
	else
		return bin(mid+1,j);
}
int main()
{
    cin>>n>>m;
    rep(i,0,n)cin>>a[i];
    printf("%lld\n",bin(0,100000000000000000LL));
    return 0;
}
