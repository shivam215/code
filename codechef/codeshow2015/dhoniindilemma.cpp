#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,z;
    long long a[10004];
    long long b[10004];
    long long res,temp,j,i;
    cin>>t;
    while(t--)
    {
        cin>>n>>z;
        for(i=0;i<n;i++)cin>>a[i];
        b[0]=0;
        for(i=1;i<=n;i++)
        {
            b[i] = b[i-1]^a[i-1];
        }
        res = INT_MAX;
        for(i=0;i<=n-z;i++)
        {
            temp = b[i+z]^b[i];
            if(temp<=res)
            {res=temp;
            j=i;}

        }
        cout<<j+1<<endl;
    }
    return 0;
}
