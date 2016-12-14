#include <bits/stdc++.h>
using namespace std;
map<int,int> m;
void primefactors(int n)
{
    while(n%2==0)
    {
       m[2]++;
       n =  n/2;
    }
    for(int i=3;i<=sqrt(n);i=i+2)
    {
        while(n%i==0)
        {
            m[i]++;
            n = n/i;
        }
    }
    if(n>2)m[n]++;
}
int main()
{
    int t,n;
    int a[11];
    cin>>t;
    while(t--)
    {
        cin>>n;
        m.clear();
        for(int i=0;i<n;i++)
        {cin>>a[i];
        primefactors(a[i]);
        }
        map<int,int>::iterator it;
        long long res =1;
        for(it=m.begin();it!=m.end();it++)
        {
            res = res*(it->second+1);
        }
        cout<<res<<endl;
    }
    return 0;
}
