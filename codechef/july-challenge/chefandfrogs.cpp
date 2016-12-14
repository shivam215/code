#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
struct data
{
    long long a;
    long long b;
};
bool myfunction(const data &p, const data &q)
{
    return(p.b<q.b);
}
int main()
{
    long long n,k,p,i;
    long long x,y;
    cin>>n>>k>>p;
    struct data arr[n];
    long long v[100005]={0};
    for(i=0;i<n;i++)
    {
        arr[i].a = i;
        cin>>arr[i].b;
    }
    sort(arr,arr+n,myfunction);
    /*for(i=0;i<n;i++)
    {
        cout<<arr[i].a<<'\t'<<arr[i].b<<endl;
    }*/
    long long j=1;
    for(i=0;i<n-1;i++)
    {
        long long diff = abs(arr[i+1].b - arr[i].b);
        if(diff<=k)
        {
            v[arr[i].a]=j;
            v[arr[i+1].a] = j;
        }
        else
        {
            j++;
        }
    }
    while(p--)
    {
        cin>>x>>y;
        x--;y--;
        if(x==y)
        {cout<<"Yes"<<endl;
        continue;
        }
        //cout<<v[x]<<v[y]<<endl;
        /*for(i=0;i<n;i++)
        {
            cout<<v[arr[i].a]<<endl;
        }*/
        if((v[x]==v[y])&&(v[x]!=0))
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;

    }
    return(0);

}
