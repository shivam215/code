#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t,n,i;
    bool flag;
    string s;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cin>>s;
        for(i=0;i<s.size();i++)
        {
            if(s[i]=='I')
            {cout<<"INDIAN"<<endl;break;}
            else if(s[i]=='Y')
            {
                cout<<"NOT INDIAN"<<endl;
                break;
            }
        }
        if(i==s.size())
            cout<<"NOT SURE"<<endl;
    }
    return(0);
}
