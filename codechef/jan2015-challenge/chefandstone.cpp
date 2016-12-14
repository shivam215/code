#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    long long t,n,k,i;
    long long a[100005],b[100005];
    long long res;
    cin>>t;
    while(t--)
    {
       cin>>n>>k;
       for(i=0;i<n;i++)
       {
           cin>>a[i];
       }
       for(i=0;i<n;i++)
       {
           cin>>b[i];
       }
       res = (k/a[0])*b[0];
       for(i=1;i<n;i++)
       {
           long long temp = (k/a[i])*b[i];
           if(temp>res)
           {
               res = temp;
           }
       }
       cout<<res<<endl;

    }
    return(0);
}
