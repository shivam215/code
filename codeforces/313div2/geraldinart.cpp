#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x,y,a[2],b[2];
    int flag=0;
    cin>>x>>y>>a[0]>>a[1]>>b[0]>>b[1];
    for(int i=0;i<=1;i++)
    {
        for(int j=0;j<=1;j++)
        {
            if(a[i]+b[j]<=x && a[1-i]<=y && b[1-j]<=y)flag=1;
            if(a[i]+b[j]<=y && a[1-i]<=x && b[1-j]<=x)flag=1;

        }
    }
    if(flag)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
