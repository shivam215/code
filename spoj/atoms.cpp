#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t;
    ll n,m,k,res;
    cin>>t;
    while(t--)
    {
        cin>>n>>k>>m;
        if(m<n)res=0;
        else res = (log2(m)-log2(n))/log2(k);
        cout<<res<<endl;
    }
    return 0;
}
