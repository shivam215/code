#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    string s;
    cin>>n>>s;
    int z=0,o=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='0')z++;
        else o++;
    }
    int res = max(z,o)-min(z,o);
    cout<<res<<endl;
}
