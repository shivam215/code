#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    long long res,x,y,mini;
    cin>>t;
    while(t--)
    {

        cin>>x>>y;
        x = abs(x);
        y=abs(y);
        mini = min(x,y);
        x = x-mini;
        y = y-mini;
        res = 0;
        res = mini*2;
        if(x==0)
            res = res + (y/2)*3 + (y+1)/2;
        if(y==0)
            res = res + x/2 + ((x+1)/2)*3;
        cout<<res<<endl;

    }
    return(0);
}
