#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int prime[100005];
void sieve()
{
    for(int i=1;i<100005;i++)prime[i]=1;
    for(int i=2;i*i<100005;i++)
    {
        if(prime[i]==1)
        {
            for(int j=i*i;j<100005;j+=i)
            {
                prime[j]=0;
            }
        }
    }
}
int main()
{
    int t,n,k,i,j;
    vector<int> vec;
    cin>>t;
    sieve();
    while(t--)
    {
        vec.clear();
        cin>>n>>k;
        if(k==0)
        {
            ll res = (n*(n-1))/2;
            cout<<res<<endl;
            continue;
        }
        for(i=2;i<=n;i++)
        {
            if(prime[i])vec.push_back(i);
        }
        ll ans=0,lefttot,righttot,left;
        for(i=0,j=k-1;i<vec.size()-k+1,j<vec.size();i++,j++)
        {
            if(i==0)left=2;
            else left = vec[i-1]+1;
            lefttot = vec[i]-left+1;
            righttot = n-vec[j]+1;
            ans = ans + lefttot*righttot;
            //cout<<ans<<endl;
        }
        cout<<ans<<endl;
    }
    return 0;
}
