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
    while(1)
    {
        int n;
        cin>>n;
        if(n==0)break;
        int res = (n*(n+1)*(2*n+1))/6;
        cout<<res<<endl;
    }
    return 0;
}
