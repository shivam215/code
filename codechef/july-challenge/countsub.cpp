#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t,i,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        char a[n+1];
        cin>>a;
        long long coun=0;
        for(i=0;i<n;i++)
        {
            if(a[i]=='1')
                coun++;
        }
        cout<<coun+(coun*(coun-1))/2<<endl;
    }
    return(0);
}
