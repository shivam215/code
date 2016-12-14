#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,a[100005],need;
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    int need1=-1;
    int flag=1;
    for(int i=0;i<n;i++)
    {
        if(i&1)need = (a[i]-i+n)%n;
        else need = (i-a[i]+n)%n;
        if(need1==-1)need1=need;
        else
        {
            if(need!=need1){flag=0;break;}
        }

    }
    if(flag)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
