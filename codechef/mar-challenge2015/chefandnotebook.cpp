#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t,x,y,k,n,a,b;
    cin>>t;
    while(t--)
    {
        cin>>x>>y>>k>>n;
        int diff = x-y;
        int flag=0;
        while(n--)
        {
            cin>>a>>b;
            if(a>=diff && k>=b)flag=1;
        }
        if(flag)cout<<"LuckyChef"<<endl;
        else cout<<"UnluckyChef"<<endl;
    }
    return 0;
}
