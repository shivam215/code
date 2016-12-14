#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j;
    vector< pair<int,int> > v;
    cin>>n;
    int pos=0,neg=0;
    for(i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        if(a<0)neg++;
        else pos++;
        v.push_back(make_pair(a,b));
    }
    sort(v.begin(),v.end());
    int mn = min(neg,pos);
    i=0;j=n-1;
    if(mn==neg)
    {
        while(i<neg-mn)i++;
        if(mn==pos)while(j>n-1-pos+mn)j--;
        else while(j>n-1-pos+mn+1)j--;
    }
    else
    {
        while(j>n-1-pos+mn)j--;
        if(mn==neg)while(i<neg-mn)i++;
        else while(i<neg-mn-1)i++;
    }
    int sum=0;
    for(int k=i;k<=j;k++)
    {
        sum = sum + v[k].second;
    }
    cout<<sum<<endl;
    return 0;
}
