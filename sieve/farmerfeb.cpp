#include <bits/stdc++.h>
using namespace std;
int prime[2010];
void sieve()
{
    for(int i=1;i<2010;i++)prime[i]=1;
    for(int i=2;i*i<2010;i++)
    {
        if(prime[i]==1)
        {
            for(int j=i*i;j<2010;j+=i)
            {
                prime[j]=0;
            }
        }
    }
}
int main()
{
    int t,x,y,sum,i;
    cin>>t;
    sieve();
    while(t--)
    {
        cin>>x>>y;
        sum = x+y;
        int res=1;
        for(i=sum+1;prime[i]!=1;i++)
        {
            res++;
        }
        cout<<res<<endl;
    }
    return 0;
}
