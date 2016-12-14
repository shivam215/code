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
ll a[100005];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    ll g = a[0];
    for(int i=1;i<n;i++)
    {
        g = __gcd(g,a[i]);
    }
    for(int i=0;i<n;i++)
    {
        a[i] = a[i]/g;
    }
    int flag=0;
    for(int i=0;i<n;i++)
    {
        while((a[i]%2)==0)
        {
            a[i] = a[i]/2;
        }
        while((a[i]%3)==0)a[i]=a[i]/3;
        if(a[i]>1)
        {
            flag=1;break;
        }
    }
    if(!flag)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
