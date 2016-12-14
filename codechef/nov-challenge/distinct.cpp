#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);cin.tie(0);
using namespace std;
int main()
{
    int T,i,count,j;
    char a[100000];
    int b[26];
    cin>>T;
    for(i=1;i<=T;i++)
    {
        cin>>a;
        count = 0;
        for(j=0;j<26;j++)
        {
            b[j]=0;
        }
        for(j=0;a[j]!='\0';j++)
        {
            b[a[j]-97]++;
        }
        for(j=0;j<26;j++)
        {
            if(b[j]!=0)
                count++;
        }
        cout<<count<<endl;
    }
    return(0);
}
