#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,coun=0,res=0,temp,i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>temp;
        if(temp>0)
        {
            coun = coun+1;
        }
        else
        {
            res = max(res,coun);
            coun=0;
        }
    }
    res = max(res,coun);
    cout<<res<<endl;
}
