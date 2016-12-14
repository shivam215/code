#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,i,j,k,flag;
    string s;
    char c,d;
    map <char,char> f;
    cin>>t;
    while(t--)
    {
        cin>>n;
        f.clear();
        while(n--)
        {
            cin>>c>>d;
            f[c] = d;
        }
        cin>>s;
        for(i=0;i<s.size();i++)
        {
            if(f[s[i]])
            {
                s[i] = f[s[i]];
            }
        }
        i=0;j=s.size()-1;
        while(s[i]=='0')
        {
            i++;
        }
        flag=1;
        for(j=0;j<s.size();j++)
        {
            if(s[j]=='.')
            {
                flag=0;
                break;
            }
        }
        j=s.size()-1;
        if(flag==0)
        {
           while(s[j]=='0')
        {
            j--;
        }
        if(s[j]=='.')
            j--;
        }
        if(i>j)
        {
            printf("0\n");
            continue;
        }
        for(k=i;k<=j;k++)
        {
            printf("%c",s[k]);
        }
        printf("\n");
    }
    return 0;
}
