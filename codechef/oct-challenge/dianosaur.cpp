#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);cin.tie(0);
using namespace std;
int main()
{
    int T,a[100001],n,i;
    long long res,cur;
    cin>>T;
    while(T--)
    {
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        cur=0;
        res=0;
        for(i=0;i<n;i++)
        {
           cur+=a[i];
           res+=abs(cur);
        }
        cout<<res<<endl;
    }
    return(0);
}
