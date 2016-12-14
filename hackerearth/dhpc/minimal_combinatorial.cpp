#include <iostream>
using namespace std;
int main()
{
    int t,r,n,i;
    long long int a;
    cin>>t;
    while(t--)
    {   a = 1;
        cin>>n>>r;
        if(n-r<r)
            r = n-r;
        for(i=1;i<=r;i++)
        {
            a = (a*(n-i+1))/i;
        }
        cout<< a<<endl;}}
