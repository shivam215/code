#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T,N,K;
    long long a[22],sum;
    cin>>T;
    while(T--)
    {
        cin>>N>>K;
        long long b[K];
        sum = 0;
        for(i=0;i<N;i++)
        {
            cin>>a[i];
            sum = sum+a[i];
        }
        if((sum%k)!=0)
        {
            cout<<"NO"<<endl;
            continue;
        }
        sum = sum/K;
        sort(a,a+N);
        for(i=N-1;i>=0;i--)
        {
            if(a[i]+a[i-1]>sum)
            {
                b[]
            }
        }

    }
}
