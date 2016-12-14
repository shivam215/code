#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,m,temp,i,m1,m2;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        m1=0;m2=0;
        for(i=0;i<n;i++)
        {
            cin>>temp;
            m1 = max(m1,temp);
        }
        for(i=0;i<m;i++)
        {
            cin>>temp;
            m2 = max(m2,temp);
        }
        if(m1>=m2)cout<<"Godzilla"<<endl;
        else cout<<"MechaGodzilla"<<endl;
    }
    return 0;
}
