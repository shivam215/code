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
int a[500*500+5];
int main()
{
    int n;
    cin>>n;
    rep(i,0,n*n)
    {
        cin>>a[i];
    }
    sort(a,a+n*n);
    int num=a[0];
    vector<int> res;
    int cnt=1;
    rep(i,1,n*n)
    {
        if(a[i]==num)
        {
            cnt++;
        }
        else
        {
            if(cnt&1)res.pb(num);
            num =a[i];
            cnt=1;
        }
    }
    if(cnt&1)res.pb(num);
    rep(i,0,res.size())printf("%d ",res[i]);
    printf("\n");
    return 0;
}
