#include <bits/stdc++.h>
using namespace std;
int a[100005],b[100005],c[100005];
int main()
{
    int n,i;
    vector<int> vec;
    cin>>n;
    for(i=1;i<=n;i++)cin>>a[i];
    b[1]=a[1];
    for(i=2;i<=n;i++)b[i]=max(b[i-1],a[i]);
    c[n]=a[n];
    for(i=n-1;i>=1;i--)c[i]=max(c[i+1],a[i]);
    vec.push_back(1);
    vec.push_back(n);
    for(i=2;i<n;i++)
    {
        int first = b[i-1];
        int second = c[i+1];
        if(a[i]>first || a[i]>second)vec.push_back(i);
    }
    sort(vec.begin(),vec.end());
    for(i=0;i<vec.size();i++)
    {
        cout<<vec[i]<<' ';
    }
    cout<<endl;
    return 0;


}
