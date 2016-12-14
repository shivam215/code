#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t,n,k,temp,coun;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        coun=0;
        for(int i=0;i<n;i++)
        {
            cin>>temp;
            if(!(temp&1))
                coun++;
        }
        if(k==0&&coun==n)
        {
            cout<<"NO"<<endl;
            continue;
        }
        if(coun>=k)
        {
            cout<<"YES"<<endl;
        }
        else
            cout<<"NO"<<endl;

    }
    return(0);
}
