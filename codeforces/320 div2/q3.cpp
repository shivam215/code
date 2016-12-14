#include <bits/stdc++.h>
#define inf 100000000
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
int main()
{
    ll a,b;
    cin>>a>>b;
    if(b>a)
    {
        cout<<-1<<endl;
        return 0;
    }
    if(a==b)
    {
        cout<<a<<endl;
        return 0;
    }
    ll k1 = (a-b)/(2*b);
    ll k2 = (a+b)/(2*b);
    double x1 = (double)(a-b)/(double)(2*k1);
    double x2 = (double)(a+b)/(double)(2*k2);
    if(x1<x2)printf("%.12f\n",x1);
    else printf("%.12f\n",x2);
    return 0;
}
