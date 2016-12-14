#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);cin.tie(0);
using namespace std;
int main()
{
    int T,N,M,a[101],coun,i,max;
    cin>>T;
    while(T--)
    {
        cin>>N>>M;
        for(i=0;i<N;i++)
        {
            cin>>a[i];
        }
        max = a[0];
        for(i=1;i<N;i++)
        {
            if(a[i]>max)
                max = a[i];
        }
        coun=0;
        for(i=0;i<N;i++)
        {
            coun = coun + max-a[i];
        }
        if((M-coun)%N==0)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return(0);
}
