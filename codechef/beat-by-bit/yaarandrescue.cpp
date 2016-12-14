#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    ll i,j,n;
    string s[1001];
    string x;
    ll a[1004][26];
    cin>>t;
    while(t--)
    {
       cin>>n;
       for(i=0;i<1004;i++){for(j=0;j<26;j++)a[i][j]=0;}
       for(i=1;i<=n;i++)
       {
           cin>>s[i];
           for(j=0;j<(s[i].size());j++)
           {
               //cout<<s[i][j]<<endl;
               a[i][s[i][j]-'a']++;
           }

       }
       //for(i=0;i<26;i++)cout<<a[1][i]<<' '<<a[2][i]<<' '<<a[3][i]<<endl;
       cin>>x;
       ll b[26];
       for(i=0;i<26;i++)b[i]=0;
       for(i=0;i<x.size();i++)b[x[i]-'a']++;
       //for(i=0;i<26;i++)cout<<b[i]<<endl;
       for(i=1;i<=n;i++)
       {
           for(j=0;j<26;j++)
           {
               if(a[i][j]<b[j])break;
           }
           if(j==26)cout<<s[i]<<' ';
       }
       cout<<endl;
    }
    return 0;
}
