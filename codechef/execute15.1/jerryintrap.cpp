#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t,temp,n;
    int a[1005];
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<1005;i++)
            a[i]=0;
        for(int i=1;i<n;i++)
        {
            cin>>temp;
            a[temp]=1;
        }
        for(int i=1;i<=n;i++)
        {
            if(a[i]==0)
                {cout<<i<<endl;
                break;}
        }
    }
    return(0);
}
