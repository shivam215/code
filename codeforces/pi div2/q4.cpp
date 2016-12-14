#include <bits/stdc++.h>
using namespace std;
map<int,int> mp;
int main()
{
    ios_base::sync_with_stdio(false);
    int n,k,a,m,i;
    int arr[200005];
    cin>>n>>k>>a>>m;
    for(i=1;i<=m;i++)cin>>arr[i];
    int total = (n+1)/(a+1);
    mp[n+1]=n;
    map<int,int>::iterator it;
    for(i=1;i<=m;i++)
    {
        int cur = arr[i];
        it = mp.upper_bound(cur);
        int space = it->second;
        int left = it->first-space;
        mp[cur] = cur-left;
        mp[it->first] = space-mp[cur]-1;
        int prevship = (space+1)/(a+1);
        int nowship = (mp[cur]+1)/(a+1) + (mp[it->first]+1)/(a+1);
        int diff = prevship - nowship;
        total = total - diff;
        if(total<k)break;
    }
    if(i<=m)printf("%d\n",i);
    else printf("-1\n");
    return 0;

}
