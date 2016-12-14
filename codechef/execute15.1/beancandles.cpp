#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t,mn,i,j;
    int a[10];
    cin>>t;
    while(t--)
    {
        for(i=0;i<10;i++)
            cin>>a[i];
        mn=a[1];
        j=1;
        for(i=2;i<10;i++)
        {
            if(a[i]<mn)
            {
                mn = a[i];
                j=i;
            }
        }
        //cout<<j<<mn<<endl;
        for(i=0;i<=mn;i++)
        {
            if(i==mn&&a[0]==0)
                cout<<"0";
            else
                cout<<j;
        }
        cout<<endl;

    }
    return(0);
}
