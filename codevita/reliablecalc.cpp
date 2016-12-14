#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    double n,f,t;
        cin>>n;
        while(n<=0)
        {
            cout<<"Invalid Input"<<endl;
            cin>>n;
        }
        cin>>f;
        while(f<0)
        {
            cout<<"Invalid Input"<<endl;
            cin>>f;

        }
        cin>>t;
        while(t<=0)
        {
            cout<<"Invalid Input"<<endl;
            cin>>t;

        }
        if(f==0)
        {
            cout<<"Total Down Time: 0"<<endl;;
            cout<<0<<endl;
            cout<<0<<endl;
            cout<<"100%"<<endl;
            return 0;
        }
        ll mtbf = (n/f-t/f)+0.5;
        ll mttr =(t/f)+0.5;
        ll aval = (mtbf/(mtbf+mttr))*100 + 0.5;
        cout<<mtbf<<endl;
        cout<<mttr<<endl;
        cout<<aval;
        cout<<"%"<<endl;

    return 0;
}

