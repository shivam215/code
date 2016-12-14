#include <bits/stdc++.h>
#define pb push_back
#define scanll(x) scanf("%lld",&x)
#define mp make_pair
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int main()
{
    ll n,res=0,temp;
    scanll(n);
    while(n--)
    {
        scanll(temp);
        res = res^temp;
    }
    printf("%lld\n",res);
    return 0;
}
