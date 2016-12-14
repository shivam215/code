#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m,d,i;
    char c;
    int a[100001];
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    i=0;
    while(m--)
    {
        cin>>c>>d;
        if(c=='C')
        {
            i = (i+d)%n;
        }
        else if(c=='A')
        {
            i = (i+n-d)%n;
        }
        else
        {
            cout<<a[(i+d-1)%n]<<endl;
        }
    }
    return(0);
}
