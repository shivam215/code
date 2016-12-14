#include <bits/stdc++.h>
using namespace std;
int main()
{

    long long res=0,i,n;
    cin>>n;
    for(i=1;i*i<=n;i++)
    {
        res = res + n/i - (i-1);
    }
    cout<<res<<endl;
}
