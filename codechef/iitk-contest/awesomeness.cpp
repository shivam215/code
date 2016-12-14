#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    char ch[100005],k;
    int ar[26]={0};
    int coun,j,m,i;
    cin>>ch;
    k = ch[0];
    coun=1;
    for(i=1;ch[i]!='\0';i++)
    {
        if(ch[i]==k)
        {
            coun++;
        }
        else
        {
           if(coun>ar[k-97]){ar[k-97]=coun;}
           k = ch[i];
           coun=1;
        }
    }
    if(coun>ar[k-97])ar[k-97]=coun;
    m = ar[0];
    j=0;
    for(i=1;i<26;i++)
    {
        if(ar[i]>m)
        {
          m = ar[i];
          j=i;
        }
    }
    cout<<char(j+97)<<endl<<m<<endl;
    return(0);
}
