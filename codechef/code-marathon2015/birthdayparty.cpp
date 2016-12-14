#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int t,n,q,i,x,y,c;
    int a[100005],b[100005];
    cin>>t;
    while(t--)
    {
        cin>>n>>q;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for(i=0;i<n;i++)
        {
            cin>>x>>y;
            b[x]++;
            b[y+1]--;
        }
        c=0;
        for(i=0;i<100005;i++)
        {
            c+=b[i];
            a[i]+=c;
        }
        while(q--)
        {
            cin>>x;
            printf("%d\n",a[x]);
        }
    }
    return 0;
}
