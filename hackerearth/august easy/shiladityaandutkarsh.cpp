#include<bits/stdc++.h>
using namespace std;
int  f(int i)
{
    return i*(i-1);
}

int main()
{
     int n;
     cin>>n;
     long long ans=0;
     for(int i=3;i<=n;i++)
     {
         ans=ans+(long long)f(i-1);
     }
     cout<<ans<<"\n";
    return 0;
}
