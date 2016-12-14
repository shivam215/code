#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    double T1,T2,t1,t2,temp;
    double res;
    cin>>t;
    while(t--)
    {
        cin>>T1>>T2>>t1>>t2;
        if(t1==0&&t2==0)
        {
            cout<<0<<endl;
            continue;
        }
        temp = T2*T1;
        if(T2-t1>0)
        {
            if(T2-t1<T1)temp = temp - ((T2-t1)*(T2-t1)*0.5);
            else temp = temp - T1*(T2-t1-T1) - (T1*T1*0.5);
        }

        if(T1-t2>0)
        {
            if(T1-t2<T2)temp = temp - ((T1-t2)*(T1-t2)*0.5);
            else temp = temp - T2*(T1-t2-T2) - (T2*T2*0.5);

        }

        res = temp/(T1*T2);
        printf("%1f\n",res);
    }
    return 0;
}
