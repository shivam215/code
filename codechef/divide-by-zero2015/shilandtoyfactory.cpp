#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    ll k,i,n,sum,low,high,mid;
    ll a[1003];
    cin>>k>>n;
    for(i=0;i<k;i++)cin>>a[i];
    low = 1LL;high=10000000000000LL;
    while(low<high)
    {
        mid = (low+high)/2;
        sum = 0;
        for(i=0;i<k;i++)sum = sum + (mid/a[i]);
        if(sum>=n)
        {
            high = mid;
        }
        else
        {
            low = mid+1;
        }
    }
    cout<<high<<endl;
    return 0;
}
