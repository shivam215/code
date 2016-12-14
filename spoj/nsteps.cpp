#include <bits/stdc++.h>
#define scanint(x) scanf("%d",&x)
#define scanll(x) scanf("%lld",&x)
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
    int n;
    scanint(n);
    while(n--)
    {
        int x,y;
        scanint(x);
        scanint(y);
        if(x-y==2||x==y)
        {
            int res = x + y -(x&1);
            cout<<res<<endl;
        }
        else
        {
            cout<<"No Number"<<endl;
        }
    }
    return 0;

}
