#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
int main()
{
    int T,i;
    char s[100001];
    long long res,level;
    cin>>T;
    while(T--)
    {
        cin>>s;
        level = 1;
        res = 1;
        for(i=0;s[i]!='\0';i++)
        {
            if(level&1)
            {
                if(s[i]=='l')
                    res = (2*res)%mod;
                else
                {
                    res = ((2*res)+2)%mod;
                }
            }
            else
            {
                if(s[i]=='l')
                    res = ((2*res)-1)%mod;
                else
                    res = ((2*res)+1)%mod;
            }
            level++;
        }
        cout<<res<<endl;
    }
    return(0);
}
