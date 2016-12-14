#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int t,coun1,coun2,i;
    char c;
    string s;
    cin>>t;
    while(t--)
    {
        coun1=0;coun2=0;
        cin>>s;
        for(i=0;s[i]!='\0';i++)
        {
            if(i&1)
            {
                if(s[i]!='-')
                    coun1++;
            }
            else
            {
                if(s[i]!='+')
                    coun1++;
            }
        }
        for(i=0;s[i]!='\0';i++)
        {
            if(i&1)
            {
                if(s[i]!='+')
                    coun2++;
            }
            else
            {
                if(s[i]!='-')
                    coun2++;
            }
        }
        cout<<min(coun1,coun2)<<endl;
    }
    return(0);
}
