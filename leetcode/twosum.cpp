#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,target;
    cin>>n;
    int a[n+1],inv[n+1];
    for(i=0;i<n;i++)cin>>a[i],inv[a[i]]=i;
    cin>>target;
    sort(a,a+n);
    i=0,j=n-1;
    while(i<j)
    {
        if(a[i]+a[j]==target)break;
        else if(a[i]+a[j]>target)j--;
        else i++;
    }
    cout<<inv[a[i]]+1<<' '<<inv[a[j]]+1<<endl;
}
