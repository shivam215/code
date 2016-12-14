#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    int flag;
    while(1)
    {
        cin>>n;
        if(n==-1)break;
        if(n==1){cout<<"Y"<<endl;continue;}
        flag=1;
        n = n+5;
        if(n%6==0)n=n/6;
        else flag=0;
        if(flag)
        {
            while(n%2==0)
            {
                n = n/2;
            }
            if(n!=1)flag=0;
        }
        if(flag)cout<<"Y"<<endl;
        else cout<<"N"<<endl;

    }
    return 0;
}
