#include <bits/stdc++.h>
#define scanint(x) scanf("%d",&x)
#define scanll(x) scanf("%lld",&x)
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
double a[1005];
int main()
{
    freopen("B-large-practice.in","r",stdin);
    freopen("B-large-practice.out","w",stdout);
    int t;
    cin>>t;
    rep(test,1,t+1)
    {
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;i++)cin>>a[i];
        cout<<"Case #"<<test<<":"<<endl;
        while(m--)
        {
            int l,r;
            cin>>l>>r;
            double d = r-l+1;
            double sum=0;
            for(int i=l;i<=r;i++)
            {
                sum = sum + log2(a[i]);
            }
            double res = sum/d;
            res = pow(2.0,res);
            printf("%.9f\n",res);
        }
    }
    return 0;
}
