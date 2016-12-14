#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
map<ll,ll> fib;
map<ll,ll> infib;
int main()
{
    int t;
    cin>>t;
    fib[0]=0;fib[1]=1;
    infib[0]=1;infib[1]=1;
    int j=2;
    while(fib[j-1]<100000008)
    {

        fib[j] = fib[j-1]+fib[j-2];
        infib[fib[j]]=1;
        j++;
    }
    rep(test,1,t+1)
    {
        ll n,m;
        cin>>n>>m;
        ll sum=0;
        for(ll i=1;i*i<=n;i++)
        {
            if(n%i==0)
            {
                if(i!=(n/i))
                {
                    sum = (sum + i + n/i)%m;
                }
                else
                {
                    sum  = (sum + i)%m;
                }
            }
        }
        sum = ((sum - n)%m+m)%m;
        ll cnt=0;
        for(int i=1;i*i<=sum;i++)
        {
            if(sum%i==0)
            {
                if(i!=(sum/i))
                {
                    cnt+=2;
                }
                else
                {
                    cnt++;
                }
            }
        }
        if(sum>1)cnt--;
        if(infib[cnt]==1)
        {
            cout<<"Case #"<<test<<" : YES."<<endl;
        }
        else
        {
            cout<<"Case #"<<test<<" : NO."<<endl;
        }
    }
    return 0;
}
