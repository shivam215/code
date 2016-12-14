#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t,n,res,i;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int a[n],b[n];
        for(i=0;i<n;i++)
        {
            cin>>a[i]>>b[i];
        }
        res = 0;
        for(i=1;i<=n;i++)
        {
            res = res^i;
        }
        cout<<res<<endl;

    }
}
