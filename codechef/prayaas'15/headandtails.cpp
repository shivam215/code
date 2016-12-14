#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    float x,res;
    cin>>t;
    while(t--)
    {
        cin>>x;
        if(x<3){cout<<"-1"<<endl;continue;}
        if(((x+1-sqrt(x*x-2*x-3))/(2*(x+1)))>0)res =(x+1-sqrt(x*x-2*x-3))/(2*(x+1));
        else res = (x+1+sqrt(x*x-2*x-3))/(2*(x+1));
        printf("%.7f\n",res);
    }
    return 0;
}
