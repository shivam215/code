#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t,flag,i,j;
    string s;
    cin>>t;
    while(t--)
    {
        cin>>s;
        i=0;j=s.size()-1;
        flag=1;
        while(i<j)
        {
            if(s[i]!=s[j]){flag=0;break;}
            i++;j--;
        }
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
