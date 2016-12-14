#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    ll res,i,j,diff;
    string s;
    vector<ll> v[30];
    cin>>t;
    while(t--)
    {
        cin>>s;
        res=0;
        for(i=0;i<30;i++)v[i].clear();
        for(i=0;i<s.size();i++)
        {
            res++;
            for(j=0;j<v[s[i]-'a'].size();j++)
            {
                diff = i - v[s[i]-'a'][j]+1;
                if(diff&1)res++;
            }
            v[s[i]-'a'].push_back(i);
        }
        printf("%lld\n",res);
    }
    return 0;
}
