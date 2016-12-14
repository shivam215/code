#include <bits/stdc++.h>
#define MAX 1000000
using namespace std;
int arr[1000001]={0};
int main()
{
    int test,n,i,k;
    int a[100005];
    vector<int> prime;
    for(int i=2;i<=MAX;i++)
    {
        if(!arr[i])
        {
            prime.push_back(i);
            if(i>1000)continue;
            for(int j=i*i; j<MAX; j += i)
                arr[j]=1;
        }
    }
    //for(i=0;i<100;i++)
        //cout<<prime[i]<<'\t';
    cin>>test;
    while(test--)
    {
        vector<int> cnt(prime.size());
        for(i=0;i<cnt.size();i++)
            cnt[i]=0;
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(i=0;i<n;i++)
        {
            if(a[i]==1)
                continue;
            for(k=0;prime[k]*prime[k]<=a[i];k++)
            {
                if(a[i]%prime[k]==0)
                {
                    int t=0;
                    while(a[i]%prime[k]==0)
                    {
                        t++;
                        a[i] = (a[i]/prime[k]);
                    }
                    if(cnt[k]<t) cnt[k]=t;
                }

            }
            if(a[i]!=1)
            {
                int pos = lower_bound(prime.begin(),prime.end(),a[i])-prime.begin();
                if(cnt[pos]<1) cnt[pos]=1;
            }

        }
        int ans=0;
        for(i=0;i<cnt.size();i++)
            ans+=cnt[i];
        cout<<ans<<endl;

    }
    return(0);
}
