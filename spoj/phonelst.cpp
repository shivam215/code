#include <bits/stdc++.h>
#define scanint(x) scanf("%d",&x)
#define scanll(x) scanf("%lld",&x)
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
bool isPrefix(string const& s1, string const&s2)
{
    const char*p = s1.c_str();
    const char*q = s2.c_str();
    while (*p&&*q)
        if (*p++!=*q++)
            return false;
    return true;
}
int main()
{
    int t;
    string s[10004];
    scanint(t);
    while(t--)
    {
        int n;
        scanint(n);
        for(int i=0;i<n;i++)cin>>s[i];
        sort(s,s+n);
        int flag=0;
        for(int i=0;i<n-1;i++)
        {
            if(isPrefix(s[i],s[i+1]))
            {
                flag=1;
                break;
            }
        }
        if(flag)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;

    }
    return 0;
}
