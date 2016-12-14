#include <bits/stdc++.h>
#define mod 1000000007
#define mx 1000006
using namespace std;
typedef long long ll;
map<ll,ll> mp;
int mark[mx];
vector<ll> v;
void sieve()
{
    for(ll i=2;i*i<mx;i++)
    {
        if(!mark[i])
        {
            v.push_back(i);
            for(ll j=i*i;j<mx;j+=i)
            {
                mark[j]=1;
            }
        }
    }
    /*for(ll i=2;i<mx;i++)
    {
        if(!mark[i])v.push_back(i);
    }*/
}
ll gcd(ll a, ll b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
ll fastexp(ll a, ll b)
{
    ll res =1;
    while(b>0)
    {
        if(b%2==1)res=(res*(a%mod))%mod;
        a = ((a%mod)*(a%mod))%mod;
        b>>=1;
    }
    return res;
}
int main()
{
   ios_base::sync_with_stdio(false);
   int t;
   ll n,i,a[101],j;
   cin>>t;
   sieve();
   while(t--)
   {
       cin>>n;
       mp.clear();
       for(i=0;i<n;i++)cin>>a[i];
       int vis[n];
       memset(vis,0,sizeof(vis));
       for(i=0;i<n;i++)
       {
           for(j=0;j<v.size()&&v[j]<=a[i];j++)
           {
               while(a[i]%v[j]==0)
               {
                   a[i] = a[i]/v[j];
                   mp[v[j]]++;
               }
           }
       }
       for(i=0;i<n;i++)
       {
           for(j=0;j<n;j++)
           {
               ll g = gcd(a[i],a[j]);
               if(g!=1 && g!=a[i])
               {
                   mp[g]++;
                   mp[a[i]/g]++;
                   vis[i]=1;
                   break;
               }
           }
       }
       for(i=0;i<n;i++)
       {
           if(vis[i]==1)a[i]=1;
       }
       for(i=0;i<n;i++)
       {
               ll x = (ll)sqrt(a[i]);
               if(x*x==a[i])
               {
                   mp[x]+=2;
                   a[i]=1;
               }
               /*for(int d=-2;d<=2;d++)
               {
                   if(x+d>1 && (x+d)*(x+d)==a[i])
                   {
                       mp[x+d]+=2;
                       a[i]=1;
                       break;
                   }
               }*/
       }
       for(i=0;i<n;i++)
       {
           if(a[i]!=1)mp[a[i]]++;
       }
       map<ll,ll>::iterator it;
       ll res=1;
       for(it=mp.begin();it!=mp.end();++it)
       {
           ll x = it->first;
           ll y = it->second;
           if((y%3)!=0)y+=3-y%3;
           res = (res*fastexp(x,y))%mod;
       }
       printf("%lld\n",res);
   }
   return 0;
}
