#include <bits/stdc++.h>
using namespace std;
map< pair<string,string> ,int> mp;
int equi(string s1,string s2)
{
    int len = s1.size();
    if(s1==s2)return 1;
    if(len&1)return 0;
    if(mp[make_pair(s1,s2)])return mp[make_pair(s1,s2)];

    string a = s1.substr(0,len/2);
    string b = s1.substr(len/2,len/2);
    string c = s2.substr(0,len/2);
    string d = s2.substr(len/2,len/2);
    int flag=0;
    if(equi(a,c)&&equi(b,d))flag=1;
    if(!flag)if(equi(a,d)&&equi(b,c))flag=1;
    mp[make_pair(s1,s2)]=flag;
    if(flag)return 1;
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    string s1,s2;
    cin>>s1>>s2;
    if(equi(s1,s2))printf("YES\n");
    else printf("NO\n");
    return 0;
}
