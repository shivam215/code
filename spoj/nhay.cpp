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
char pat[1000006];
int lps[1000006],n;
void computeLPSArray()
{
    int len = 0;  // lenght of the previous longest prefix suffix
    int i;
    lps[0] = 0;
    i = 1;
    while (i < n)
    {
       if (pat[i] == pat[len])
       {
         len++;
         lps[i] = len;
         i++;
       }
       else
       {
         if (len != 0)
         {
           len = lps[len-1];
         }
         else // if (len == 0)
         {
           lps[i] = 0;
           i++;
         }
       }
    }
}
void KMPSearch()
{
    int j  = 0;
    ll i = 0;  // index for txt[]
    char c;
    c = getchar();
    c = getchar();
    while (c!='\n')
    {
      if (c == pat[j])
      {
        j++;
        i++;
        c = getchar();
      }

      if (j == n)
      {
        printf("%d\n", i-j);
        j = lps[j-1];
      }

      // mismatch after j matches
      else if (c!='\n'&&pat[j] != c)
      {
        // Do not match lps[0..lps[j-1]] characters,
        // they will match anyway
        if (j != 0)
         j = lps[j-1];
        else
         {i = i+1;c=getchar();}
      }
    }
}
int main()
{
    while(cin>>n)
    {
    scanf("%s",pat);
    computeLPSArray();
    KMPSearch();
    cout<<endl;
    }

}
