#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll f[1000];
int main()
{
    ll t,i,n,cur;
    cin>>t;
    f[1]=1;f[2]=1;
    i=3;
    while(f[i-1]<1000000000000000018LL)
    {
        f[i] = f[i-1]+f[i-2];
        i++;
    }
    while(t--)
    {
        cin>>n;
        i=1;cur=1;
        while(cur<n)
        {
            cur = cur + f[++i];
        }
        cout<<i<<endl;
    }
    return 0;
}
