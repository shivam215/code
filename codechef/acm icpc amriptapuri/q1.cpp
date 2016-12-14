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
int a[1005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        memset(a,0,sizeof(a));
        rep(i,0,n)
        {
            int temp;
            cin>>temp;
            a[temp]=1;
        }
        int cnt=0;
        rep(i,0,1000+5)
        {
            if(a[i])cnt++;
        }
        if(cnt==n)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
