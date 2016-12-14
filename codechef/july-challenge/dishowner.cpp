#include <bits/stdc++.h>
using namespace std;
int s[10004],a[10004];
int findfunc(int x)
{
    int j;
    if(a[x]==x)
        return x;
    else
    {
        j = findfunc(a[x]);
        a[x] = j;
        return j;
    }
}
void unionfunc(int x, int y)
{
    int xroot = findfunc(x);
    int yroot = findfunc(y);
    if(xroot==yroot)
        {cout<<"Invalid query!"<<endl;
        return;}
    if(s[xroot]>s[yroot])
        a[yroot] = xroot;
    else if(s[xroot]<s[yroot])
        a[xroot] = yroot;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t,n,q,type,x,y,i;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>s[i];
            a[i]=i;
        }
        cin>>q;
        while(q--)
        {
            cin>>type>>x;
            if(type==0)
            {
               cin>>y;
               unionfunc(x,y);
            }
            else
            {
                cout<<findfunc(x)<<endl;
            }
        }
    }
    return(0);
}
