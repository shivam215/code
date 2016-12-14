#include <bits/stdc++.h>
#define inf 100000000
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
double x = sqrt(2);
double y = sqrt(3);
int main()
{
    ll i,k,s;
    double a,b;
    cin>>i>>k>>s;
    cin>>a>>b;
    if(k==i)
    {
        double ans = (a+b)/pow(2,s);
        printf("%.5lf\n",ans);
    }
    else if(k>i)
    {
        if(((k-i)%2)==0)
        {
            double ans = pow(2,2*k-2*i-s+log2(a+b));
            printf("%.5f\n",ans);
        }
        else
        {
            double ans = pow(2,3*((i-k)/2)-s + log2(2*a+2*b*y)+(double)(k-i)/2);
            printf("%.5f\n",ans);
        }
    }
    else
    {
        if(((i-k)%2)==0)
        {
            double ans = pow(2,2*k-2*i-s+log2(a+b));
            printf("%.5f\n",ans);
        }
        else
        {
            double ans = pow(2,3*((i-k)/2)-3*(i-k)-s + log2(2*a+2*b*y)+(double)(k-i)/2);
            printf("%.5f\n",ans);
        }
    }
    return 0;
}
