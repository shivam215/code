#include <bits/stdc++.h>
#define ll long long
using namespace std;
int a[100005],b[100005];
bool comp(int a,int b)
{
    return a>b;
}
int main()
{
    while(1)
    {
        int n,i;
        cin>>n;
        if(n==0)break;
        for(i=0;i<n;i++)cin>>a[i];
        for(i=0;i<n;i++)cin>>b[i];
        sort(a,a+n);
        sort(b,b+n,comp);
        ll res=0;
        for(i=0;i<n;i++)res = res + 1ll*a[i]*b[i];
        cout<<res<<endl;
    }
    return 0;

}

