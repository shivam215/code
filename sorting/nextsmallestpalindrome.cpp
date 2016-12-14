#include <bits/stdc++.h>
using namespace std;
int intconvert(char *a)
{
    int res=0;
    for(int i=0;a[i]!='\0';i++)
    {
        res = res*10 + a[i]-'0';
    }
    return res;
}
int main()
{
    int t,i,j;
    int a[10];
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int n = s.size();
        int num = intconvert(&s[0]);
        memset(a,0,sizeof(a));
        for(i=0;i<n;i++)a[s[i]-'0']++;
        if(a[9]==n)
        {
            for(i=0;i<=n;i++)
            {
                if(i==0||i==n)cout<<'1';
                else cout<<'0';
            }
            cout<<endl;
            continue;
        }
        i=0;j=n-1;
        while(i<j)
        {
            s[j]=s[i];
            i++;
            j--;
        }
        if(intconvert(&s[0])>num)
        {
            cout<<s<<endl;
            continue;
        }
        if(i>j){i--;j++;}
        while(s[i]-'0'==9)
        {
            s[i] = '0';
            s[j] = s[i];
            i--;j++;
        }
        s[i]=s[i]+1;
        s[j]=s[i];
        cout<<s<<endl;
    }
    return 0;
}
