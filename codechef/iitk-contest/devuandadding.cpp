#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T,n;
    cin>>T;
    while(T--)
    {
        cin>>n;
        if(n==1||n==10||n==100||n==1000||n==10000||n==100000)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
    return(0);
}
