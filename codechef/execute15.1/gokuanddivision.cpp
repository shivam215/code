#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n&1)
            cout<<"NO"<<endl;
        else
            {if(n==2)
                cout<<"NO"<<endl;
            else
                cout<<"YES"<<endl;}
    }
    return(0);
}
