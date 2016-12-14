#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int main()
{
    int n,m,mx,in;
    cin>>n>>m;
    if(n==1)
    {
        cout<<1<<endl;
        return 0;
    }
          mx = n-m-1;
          in = m+1;
        if(mx<=m-2)
        {
            mx = m-2;
            in = m-1;
        }
    cout<<in<<endl;
    return 0;
}
