#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
int a[100005];
map<pair<int,int>,int> mp;
int main()
{
    int n,k;
    cin>>n>>k;
    int ans=0;
    while(k--)
    {
        int m;
        cin>>m;
        for(int i=0;i<m;i++)cin>>a[i];
        for(int i=1;i<m;i++)
        {
            if(a[i]!=a[i-1]+1)ans++;
            else
            {
                mp[pii(a[i-1],a[i])]=1;
            }
        }
    }
    for(int i=2;i<=n;i++)
    {
        if(mp[pii(i-1,i)]!=1)ans++;
    }
    cout<<ans<<endl;
    return 0;
}
