#include <iostream>
using namespace std;
typedef long long ll;
int main()
{
    int t;
    ll n,m,o,i;
    ll a[100005];
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>o;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        if(a[0]<o)
        {
            cout<<"-1"<<endl;
            continue;
        }
        ll coun=0;
        for(i=0;i<n;i++)
        {
            if(a[i]>=o)coun++;
        }
        if(coun>m)coun=m;
        cout<<coun<<endl;
    }
    return 0;
}
