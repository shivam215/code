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
int a[1003];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,q;
        cin>>n>>q;
        rep(i,0,n)cin>>a[i];
        sort(a,a+n);
        ll res=0;
        rep(i,1,n)
        {
            res += 1LL*q*(a[i]-a[i-1]);
        }
        cout<<res<<endl;

    }
    return 0;
}
