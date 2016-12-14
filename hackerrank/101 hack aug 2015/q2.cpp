#include <bits/stdc++.h>
#define scanint(x) scanf("%d",&x)
#define scanll(x) scanf("%lld",&x)
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int a[100001];

int main()
{
     int n,k,t;
     cin>>n>>k>>t;

    string s;

     cin>>s;

     rep(i,0,n)
     {
         int pn=i%k;
         if(s[i]=='0')
         {
            a[pn]++;
         }
         else if(s[i]=='1')
         {
             if(t>=a[pn]&&a[pn]!=0)
             {
                 s[i-a[pn]*k]='1';
                 s[i]='0';
                 t=t-a[pn];
             }
            else if(t<a[pn]&&t>0&&a[pn]!=0)
            {
                s[i-t*k]='1';
                s[i]='0';
                t=0;
                break;
            }
         }
     }
     cout<<s<<"\n";

    return 0;
}
