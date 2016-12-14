#include <bits/stdc++.h>
#define inf 1000000009
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
int a[20004];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        for(int i=0;i<n;i++)cin>>a[i];
        if(k==1)
        {
            cout<<0<<endl;
            continue;
        }
        sort(a,a+n);
        int res=inf;
        for(int i=0;i<n-k+1;i++)
        {
            res = min(res,a[i+k-1]-a[i]);
        }
        cout<<res<<endl;
    }
}
