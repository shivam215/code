#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);cin.tie(0);
using namespace std;
int main()
{
    int T,i,N,count,j;
    int a[100000],b[100001];
    cin>>T;
    for(i=1;i<=T;i++)
    {   count = 0;
        for(j=0;j<100001;j++)
        {
            b[j] = 0;
        }
        cin>>N;
        for(j=0;j<N;j++)
        {
           cin>>a[j];
           b[a[j]]++;
        }
        for(j=0;j<100001;j++)
        {
           if(b[j]!=0)
                count++;
        }
        cout<<count<<endl;

    }
    return(0);

}
