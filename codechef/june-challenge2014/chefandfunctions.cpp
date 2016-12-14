#include <bits/stdc++.h>
#define ll long long
#define M 1000000007
#include <math.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    ll n,q,x,i;
    ll a[10004],b[10004];
    cin>>t;
    while(t--)
    {
       cin>>n>>q;
       b[0]=0;
       a[0]=0;
       for(i=1;i<=n;i++)
       {
           cin>>a[i];
           b[i]=(b[i-1]+a[i])%M;
       }
       while(q--)
       {
           cin>>x;
           ll res = ((x%M)*a[1])%M;
           /*ll k=1,c=0;
           while(k<=x)
           {
               k=k<<1;
               c++;
           }
           c=min(c,n+1);*/
           for(i=2;i<=n;i++)
           {
               ll temp = (pow((double)x,1/(double)(i)));
               //ll temp = (ll)(pow(10,log10(x)/i));
               cout<<temp<<endl;
               res = (res + temp*a[i])%M;
               if(temp==1)break;
           }
           if(i<n)
           {i++;res = (((res + b[n]-b[i-1])%M)+M)%M;}
           printf("%lld ",res);
       }
       printf("\n");
    }
    return 0;
}
