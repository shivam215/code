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
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        if(n==1)
        {
            cout<<2<<endl;
            continue;
        }
        ll x = log2(n+1);
        if((1<<x)==n+1)
        {
            ll temp = 1<<(x-1);
            cout<<temp-1<<endl;

        }
        else
        {
            cout<<-1<<endl;
        }
    }
    return 0;
}
