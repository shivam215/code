#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
ll fact[5005],ifact[5005];
map<string,int> mp;
ll fastexp(ll a, ll b)
{
    ll res=1;
    while(b>0)
    {
        if(b&1)res = (res*a)%mod;
        a = (a*a)%mod;
        b>>=1;
    }
    return res;
}
ll comb(int n, int r)
{
    ll res = (fact[n]*ifact[n-r])%mod;
    res = (res*ifact[r])%mod;
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t,n,q,i,j,k;
    ll a[5005];
    string s;
    cin>>t;
    fact[0]=1;
    ifact[0]=1;
    for(i=1;i<5001;i++)
    {
        fact[i] = (fact[i-1]*i)%mod;
        ifact[i] = (ifact[i-1]*fastexp(i,mod-2))%mod;
    }

    while(t--)
    {
        cin>>n>>q>>s;
        mp.clear();
        for(i=0;i<n;i++)
            {
                for(j=i;j<n;j++)
                {
                   string str = s.substr(i,j-i+1);
                   mp[str]++;
                }
            }
            map< string,int >::iterator it;
            memset(a,0,sizeof(a));
            for(it=mp.begin();it!=mp.end();it++)
            {
                //cout<<it->first<<' '<<it->second<<endl;
                int temp = it->second;
                for(i=1;i<=temp;i++)
                {
                    a[i] = (a[i] + comb(temp,i))%mod;
                }
            }
        while(q--)
        {
            cin>>k;
            if(k>n){printf("0\n");continue;}
            printf("%lld\n",a[k]);
        }

    }
    return 0;
}
