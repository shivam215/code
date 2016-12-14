#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    ll a,b;
    while(t--)
    {
        cin>>a>>b;
        if(a+1==b)
        {
            cout<<(a&b)<<endl;
            continue;
        }
        else
        {
            if(b%2==0)
            {
                cout<<b-2<<endl;
            }
            else
            {
                cout<<b-1<<endl;
            }
        }
    }
    return 0;
}
