#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[200005];
int main()
{
    ll n,w;
    int i,j;
    cin>>n>>w;
    for(i=0;i<2*n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+2*n);
    double x = min((double)a[0],min((double)a[n]/2.0,(double)w/(3*n)));
    //cout<<x<<endl;
    double sum = 3*n*x;
    cout<<fixed<<sum<<endl;
    return 0;
}
