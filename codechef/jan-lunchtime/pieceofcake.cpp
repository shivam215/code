#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t,i;
    string s;
    cin>>t;
    while(t--)
    {
        int a[26]={0};
        cin>>s;
        for(i=0;s[i]!='\0';i++)
        {
            a[s[i]-97]++;
        }
        int sum=0;
        for(i=0;i<26;i++)
        {
            sum = sum+a[i];
        }
        for(i=0;i<26;i++)
        {
            if(a[i]==sum-a[i])
                {cout<<"YES"<<endl;
                break;}
        }
        if(i==26)
        {cout<<"NO"<<endl;}
    }
}
