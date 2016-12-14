#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[7007];
long long fact(long long x)
{
    if(a[x])
        return a[x];
    if(x==0)
        return 1;
    long long tem = (x*fact(x-1))%m;
    a[x]=tem;
    return tem;
}
long long fac(long long x)
{
    long long sum=1;
    for(long long i=1;i<=x;i++)
    {
        sum = (sum*i)%m;
    }
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(false);
    long long i,t,temp;
    cin>>n>>m;
    fact(7000);
    long long res=0;
    for(i=0;i<n;i++)
    {
        cin>>t;
        if(t>=(m-1))
            temp=0;
        else
        {
            if(t<=7000)
                temp = a[t+1];
            else
                temp = fac(t+1);
        }
        long long tem=t;
        if(tem%2==0)
            {tem=tem/2;
            res = (res+temp-1+((((tem%m)*(t%m))%m)*((t+1)%m))%m)%m;
            }
        else
            {tem=(tem+1)/2;
            res = (res+temp-1+((((tem%m)*(t%m))%m)*(t%m))%m)%m;
    }
    }
    cout<<res<<endl;
    return 0;

}
