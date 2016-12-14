#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);cin.tie(0);
using namespace std;
int main()
{
    int t,j,i,n,x;
    cin>>t;
    while(t--)
    {   priority_queue<int>a;
        int val1=0, val2=0;
        cin>>n>>x;
        for(i=0;i<n;i++)
        {
            cin>>j;
            a.push(j);
        }
        while(!a.empty() && val1<=x && val2<=x)
        {
            if((val1+a.top())<=x)
                val1 = val1 + a.top();
            else
                val2 = val2 + a.top();
            a.pop();
        }
        if(val1<=x && val2<=x)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return(0);
}
