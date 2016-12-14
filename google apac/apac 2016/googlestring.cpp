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
string str[2] = {"001","011"};
char solve(ll n)
{
    if(n%4!=0)
    {
        ll q = n/4;
        ll rem = n%4;
        return str[q&1][rem-1];
    }
    else
    {
        return solve(n/4);
    }
}
int main()
{
    freopen("A-large-practice.in","r",stdin);
    freopen("A-large-practice.out","w",stdout);
    int t;
    cin>>t;
    rep(test,1,t+1)
    {
        ll n;
        cin>>n;
        cout<<"Case #"<<test<<": "<<solve(n)<<endl;

    }
    return 0;
}
