#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int flag=0;
    while(n--)
    {
        int temp;
        cin>>temp;
        if(temp==1)flag=1;
    }
    if(flag)cout<<-1<<endl;
    else cout<<1<<endl;
    return 0;
}
