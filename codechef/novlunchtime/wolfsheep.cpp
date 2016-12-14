#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);cin.tie(0);
using namespace std;
int main()
{
    int T,N,M,temp1,temp2,i;
    int a[15];
    cin>>T;
    while(T--)
    {
        cin>>N>>M;
        for(i=0;i<15;i++)
        {
            a[i]=0;
        }
        i = M;
        while(i--)
        {
           cin>>temp1>>temp2;
           a[temp1]++;
           a[temp2]++;
        }
        /*if(M>2)
        {
            cout<<"NO"<<endl;
            continue;
        }*/
        if(M==1||M==0)
        {
            cout<<"YES"<<endl;
            continue;
        }
        for(i=1;i<=N;i++)
        {
            if(a[i]>=M)
            {
                cout<<"YES"<<endl;
                break;}
            if(i==N)
                cout<<"NO"<<endl;
        }

    }
    return(0);
}
