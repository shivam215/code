#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,sum,diff,i,coun;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int a[n];
        sum = 0;
        coun=0;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]==0)
                coun++;
            sum = sum + a[i];
        }
        if(sum<100)
        {
            cout<<"NO"<<endl;
            continue;
        }
        if(sum==100)
        {
            cout<<"YES"<<endl;
            continue;
        }
        diff = sum - 100;
        if(diff<(n-coun))
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }

    }
    return(0);
}
