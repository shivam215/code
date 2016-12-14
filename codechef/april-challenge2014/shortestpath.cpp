#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n,x,y,cnt;
    cin>>n;
    while(n--)
    {
        cin>>x>>y;
        cnt=0;
        while(x!=y)
        {
            if(x>y){x=x/2;cnt++;}
            else{y = y/2;cnt++;}
        }
        cout<<cnt<<endl;
    }
    return 0;
}
