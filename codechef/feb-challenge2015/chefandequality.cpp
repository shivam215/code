#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int t,n,m,i,temp;
    int a[100005];
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=0;i<100005;i++)
            a[i]=0;
        for(i=0;i<n;i++)
        {
            cin>>temp;
            a[temp]++;
        }
        m=a[0];
        for(i=1;i<100005;i++)
        {
            if(a[i]>m)
                m = a[i];
        }
        cout<<(n-m)<<endl;
    }
    return 0;
}
