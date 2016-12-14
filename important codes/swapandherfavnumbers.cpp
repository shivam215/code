//This problem is to find smallest number greater than
// a given number which is composed of only 5 and 9
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t,i,j;
    string s;
    int a[10];
    cin>>t;
    while(t--)
    {
        cin>>s;
        memset(a,0,sizeof(a));
        for(i=0;i<s.size();i++)
        {
            a[s[i]-'0']++;
        }
        // if number contains only 9's
        if(a[9]==s.size())
        {
            for(i=0;i<=s.size();i++)
            {
                cout<<"5";
            }
        }
        // number contains either all the 5's or some 5's and some 9's
        else if(a[5]+a[9]==s.size())
        {
            for(i=s.size()-1;i>=0;i--)
            {
                if(s[i]=='5')
                {
                    s[i]='9';
                    break;
                }
            }
            for(i=0;i<s.size();i++)cout<<s[i];
        }
        // number contain a digit which is not from 5 and 9
        else
        {
            for(i=0;i<s.size();i++)
            {
                if(s[i]!='5'&&s[i]!='9')
                {
                    int p = (int)s[i];
                    if(p>=48 && p<=52)s[i]='5';
                    else s[i]='9';
                    break;
                }
            }
            for(j=i+1;j<s.size();j++)s[j]='5';
            for(i=0;i<s.size();i++)cout<<s[i];
        }
        cout<<endl;
    }
    return 0;
}
