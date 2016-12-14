#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    long long n,s,sum,diff,i,tem;
    cin>>t;
    while(t--)
    {
        cin>>n>>s;
        sum = (n*(n+1))/2;
        diff = (sum-s);
        if(diff==0)
        {
            cout<<"0"<<endl;
            continue;
        }
        if(diff<=n-1)
        {
            cout<<"1"<<endl;
            continue;
        }
        tem = n-1;
        for(i=n-2;i>0;i--)
        {
            if(diff>tem && diff<=tem+i)
            {
                cout<<n-i<<endl;
                break;
            }
            tem=tem+i;
        }
    }
    return(0);
}
