#include <bits/stdc++.h>
using namespace std;
struct node
{
    long long x,y,z;
};
bool comp(node a, node b)
{
    return ((pow(a.x,2)+pow(a.y,2)+pow(a.z,2))<(pow(b.x,2)+pow(b.y,2)+pow(b.z,2)));
}
int main()
{
    int t,n;
    long long d;
    struct node a[101];
    cin>>t;
    while(t--)
    {
        cin>>n>>d;
        for(int i=0;i<n;i++)
        {
            cin>>a[i].x>>a[i].y>>a[i].z;
        }
        sort(a,a+n,comp);
        int ans=1;
        for(int i=0;i<n-1;i++)
        {
            if(((pow(a[i+1].x-a[i].x,2)+pow(a[i+1].y-a[i].y,2)+pow(a[i+1].z-a[i].z,2))>d*d))
            {
                ans++;
            }
        }
        cout<<ans<<endl;
        //for(int i=0;i<n;i++)cout<<a[i].x<<' '<<a[i].y<<' '<<a[i].z<<endl;
    }
    return 0;
}
