#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int t,i;
    long long w[100005];
    long long a[100005];
    long long n,m,res,temp;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>w[i];
        }
        cin>>m;
        if(m==0)
        {
            cout<<"0"<<endl;
            continue;
        }
        a[0]=0;
        for(i=1;i<=n;i++)
            a[i] = a[i-1]+w[i];
        res=0;
        for(i=1;i<=n-m+1;i++)
        {
            temp = a[i+m-1]-a[i-1];
            if(temp>res)
                res = temp;
        }
        cout<<res<<endl;

    }
}
