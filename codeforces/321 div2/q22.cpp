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
pair<ll,ll> a[100005];
int main()
{
    int n;
    ll d;
    cin>>n>>d;
    rep(i,0,n)
    {
        cin>>a[i].fe>>a[i].se;
    }
    sort(a,a+n);
    int j=0;
    ll sum=0,res=0;
    for(int i=0;i<n;i++)
    {
        while(j<n&&a[j].fe<a[i].fe+d)
        {
            sum+=a[j].se;
            j++;
        }
        res = max(res,sum);
        sum = sum-a[i].se;
    }
    cout<<res<<endl;
    return 0;
}

