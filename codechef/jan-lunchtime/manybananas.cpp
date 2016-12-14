#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n,p,q,m,x;
    ll a[100001]={0};
    char c;
    cin>>n;
    set<int> s;
    while(n--)
    {
        cin>>p>>q;
        a[p]=q;
        s.insert(p);
    }
    cin>>m;
    while(m--)
    {
        cin>>c;
        if(c=='+')
        {
            cin>>x;
            a[x]++;
            s.insert(x);
        }
        else if(c=='-')
        {
            cin>>x;
            a[x]--;
            if(a[x]==0)s.erase(x);
        }
        else
        {
            cin>>x;
            set<int>::iterator it;
            int res=0;
            for(it=s.begin();it!=s.end();++it)
            {
               res = res + (x%(*it))*a[*it];
            }
            cout<<res<<endl;
        }
    }
    return 0;
}
