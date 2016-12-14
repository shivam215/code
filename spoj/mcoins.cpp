#include <bits/stdc++.h>
using namespace std;
int f[1000006];
int solve(int n,int k,int l)
{
    if(f[n]!=-1)return f[n];
    int a,b,c;
    if(n>1)
    {
        //a = solve(n-1,k,l);
        if(!solve(n-1,k,l))
        {
            f[n]=1;
            return 1;
        }
    }
    if(n>k)
    {
        //b = solve(n-k,k,l);
        if(!solve(n-k,k,l))

        {
            f[n]=1;
            return 1;
        }
    }
    if(n>l)
    {
         //c = solve(n-l,k,l);
         if(!solve(n-l,k,l))
        {
            f[n]=1;
            return 1;
        }
    }
    f[n]=0;
    return 0;
}
int main()
{
    int k,l,m;
    cin>>k>>l>>m;
    for(int i=0;i<1000006;i++)f[i]=-1;
    f[0]=0;
    f[1]=1;
    f[k]=1;f[l]=1;
    while(m--)
    {
        int temp;
        cin>>temp;
        int res = solve(temp,k,l);
        if(res==1)
        {
            cout<<'A';
        }
        else
        {
            cout<<'B';
        }
    }
    cout<<endl;
    return 0;

}
