#include <bits/stdc++.h>
#define ll long long
using namespace std;
void swapp(ll *a, ll *b)
{
    ll temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t,i;
    ll n,k;
    ll a[100005];
    cin>>t;
    while(t--)
    {
       cin>>n>>k;
       for(i=0;i<n;i++)cin>>a[i];
       sort(a,a+n);
       if(a[0]==0 && a[1]==0)
       {
           cout<<"-1"<<endl;
           continue;
       }
       if(k==0){cout<<"0"<<endl;continue;}
       if(n==2&&a[1]>k){cout<<"0"<<endl;continue;}
       if(n==2&&a[0]==0){cout<<"-1"<<endl;continue;}
       if(a[n-1]==1){cout<<"-1"<<endl;continue;}
       ll cnt=0;
       while(a[n-1]<=k)
       {
           a[n-2] = a[n-2]*a[n-1];
           swapp(&a[n-2],&a[n-1]);
           cnt++;
       }
       for(i=1;i<n-1;i++)
       {
           if(a[i]<=k)cnt++;
       }
       cout<<cnt<<endl;
    }
    return 0;
}
