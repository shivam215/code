#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int t,n,cnt,i,flag;
    int a[100005];
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=0;i<n;i++)cin>>a[i];
        cnt=0;flag=0;
        for(i=0;i<n-1;i++)
        {
            if(a[i]!=a[i+1] && flag==0)
            {cnt+=2;flag=1;}
            else if(a[i]!=a[i+1]&&flag==1)cnt+=1;
            else if(a[i]==a[i+1])flag=0;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
