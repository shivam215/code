#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector< pair<ll,ll> > v;
int main()
{
    ll t,i,m,n;
    ll res[100005];
    ll x,y,mx;
    cin>>t;
    while(t--)
    {
        v.clear();
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>m;
            mx=0;
            while(m--)
            {
                cin>>x>>y;
                if(x<0)x=-x;
                if(y<0)y=-y;
                mx = max(mx,x*x+y*y);
            }
            v.push_back(make_pair(mx,i));
        }
        sort(v.begin(),v.end());
        ll c=0;
        for(i=0;i<n;i++)
        {
            res[v[i].second] = c;
            c++;
        }
        for(i=0;i<n;i++)printf("%d ",res[i]);
        printf("\n");

    }
    return 0;
}
