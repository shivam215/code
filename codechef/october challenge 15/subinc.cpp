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
int a[100005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        rep(i,0,n)cin>>a[i];
        int prev=0;
        ll res=0;
        rep(i,1,n)
        {
            if(a[i]<a[i-1])
            {
                res = res + (1LL*(i-prev)*(i-prev+1))/2;
                prev = i;
            }
        }
        res = res + ((n-prev)*(n-prev+1))/2;
        printf("%lld\n",res);
    }
    return 0;
}
