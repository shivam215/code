#include <bits/stdc++.h>
using namespace std;
char s[1000000001];
int main()
{
    int t;
    long long cnt;
    cin>>t;
    while(t--)
    {
        cin>>s;
        cnt=0;
        for(int i=0;s[i]!='\0';i++)
        {
            if(s[i]=='4')
                cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
