#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    if(b==0)
        return a;
    return(gcd(b,a%b));
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t,n,q,l,r,i;
    cin>>t;
    while(t--)
    {
        cin>>n>>q;
        int a[n],b[n],c[n];
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        b[0]=a[0];
        c[n-1]=a[n-1];
        for(i=1;i<n;i++)
        {
            b[i] = gcd(b[i-1],a[i]);
        }
        for(i=n-2;i>=0;i--)
        {
            c[i] = gcd(c[i+1],a[i]);
        }
        while(q--)
        {
            cin>>l>>r;
            if(l==1)
                cout<<c[r]<<endl;
            else if(r==n)
                cout<<b[l-2]<<endl;
            else
                cout<<gcd(b[l-2],c[r])<<endl;
        }
    }
    return(0);
}
