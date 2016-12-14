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
        ll p,m;
        cin>>p>>m;
        ll x = p^m;
        int cnt=0;
        while(x>0)
        {
            if(x&1)cnt++;
            x>>=1;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
