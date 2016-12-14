#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);cin.tie(0);
using namespace std;
int checkpalin(char* a, int len, int index);
int main()
{
    int T,i,len,j,k;
    char a[100001];
    cin>>T;
    for(i=1;i<=T;i++)
    {
        cin>>a;
        len = strlen(a);
        for(j=0,k=len-1;j<k;j++,k--)
        {
            if(a[j]!=a[k])
            {
               if(checkpalin(a,len,j)||checkpalin(a,len,k))
               {
                   cout<<"YES"<<endl;
                   break;
               }
               else
               {
                   cout<<"NO"<<endl;
                   break;
               }
            }
        }
        if(j>=k)
        {
            cout<<"YES"<<endl;
        }
    }
    return(0);
}
int checkpalin(char* a, int len, int index)
{
   int i,j;
   i=0;j=len-1;
   while(i<j)
   {
       if(i==index)
       {
           i++;
       }
       else if(j==index)
       {
           j--;
       }
       if(i<j)
       {
           if(a[i]!=a[j])
           {
               return 0;
           }
           i++;
           j--;
       }
   }
   return 1;
}
