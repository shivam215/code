#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T,N,a[2001],mx;
    cin>>T;
    while(T--)
    {
        cin>>N;
        for(int i=0;i<N;i++)
        {
            cin>>a[i];
        }
        mx = a[0];
        for(int i=1;i<N;i++)
        {
            if(a[i]>mx)
                mx = a[i];
        }
        cout<<mx<<endl;
    }
    return(0);
}
