#include <iostream>
using namespace std;
int main()
{
    int t,i,n;
    cin>>t;
    for(i=1;i<=t;i++)
    {
        cin>>n;
        while(n%2==0)
        {
            n = n/2;
        }
        if(n==1)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;}
        return(0);}
