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

int main()
{    string s1,s2;
    int t;
     cin>>t;
     while(t--)
     {
         cin>>s1>>s2;
         int flag=0;
         rep(i,0,s1.length())
         {
             if(s1[i]=='?'||s2[i]=='?')
                continue;
             if(s1[i]==s2[i])continue;
             if(s1[i]!=s2[i])
              {

                flag=1;
                 break;
              }
         }
         if(flag==1)
            cout<<"No\n";
         else cout<<"Yes\n";
     }
    return 0;
}
