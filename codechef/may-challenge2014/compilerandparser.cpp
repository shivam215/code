#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    long long t,i,cur,len,flag,maxlen;
    string s;
    cin>>t;
    while(t--)
    {
        cin>>s;
        cur=0;len=0;
        for(i=0;i<s.size();i++)
        {
            if(s[i]=='<')
            {
                cur++;
            }
            else
            {
                cur--;
                if(cur==0)len=max(len,i+1);
                if(cur<0)break;

            }
        }
        cout<<len<<endl;
    }
    return 0;
}
