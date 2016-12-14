#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    set<string> myset;
    map<string,int> m;
    int t;
    string s;
    cin>>t;
    while(t--)
    {
        cin>>s;
        myset.insert(s);
        m[s]++;
    }
    set<string>::iterator it;
    for(it=myset.begin();it!=myset.end();++it)
    {
        cout<<*it<<' '<<m[*it]<<endl;
    }
    return 0;
}
