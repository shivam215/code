#include <bits/stdc++.h>
using namespace std;
long long a[400001],b[400001];
int main()
{
    long long t,n,i,j,m,d,tem,p,r,g;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(i=0;i<n;i++)
        {
            cin>>b[i];
        }
        cin>>d;
        if(a[0]>=d)m=d;
        else
        {tem = a[0]-b[0];
        p = d - a[0];
        if(p%tem==0)r = p/tem;
        else r = (p/tem)+1;
        m = (d-r*tem)+(a[0]+b[0])*r;}
        j=0;
        for(i=1;i<n;i++)
        {
            if(a[i]>=d)g=d;
            else
            {tem = a[i]-b[i];
        p = d - a[i];
        if(p%tem==0)r = p/tem;
        else r = (p/tem)+1;
        g = (d-r*tem)+(a[i]+b[i])*r;}

            if(g<m)
            {
                m = g;
                j=i;
            }
        }
        cout<<j+1<<endl;
    }
    return 0;
}
