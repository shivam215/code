#include <bits/stdc++.h>
using namespace std;
int a[2000006];
int main()
{
    int n,k,id;
    cin>>n>>k;
    memset(a,0,sizeof(a));
    for(int i=0;i<k;i++){cin>>id;a[id]=1;}
    int coun=k;
    for(int i=1;i<=n;i++)
    {
        if(a[i])continue;
        if(i==1)
        {
            if(!a[i+1]){a[i]=1;coun++;}
        }
        else if(i==n)
        {
            if(!a[i-1]){a[i]=1;coun++;}
        }
        else
        {
            if(a[i-1]==0 && a[i+1]==0)
            {
                a[i]=1;coun++;
            }
        }
    }
    cout<<coun<<endl;
}
