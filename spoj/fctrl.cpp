#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
ll fin(ll n,ll p)
{
    ll temp = p;
    ll res=0;
    while(temp<=n)
    {
        res = res + n/temp;
        temp = temp*p;
    }
    return res;

}
int main()
{
    ll t,n,two,five,res;
    cin>>t;
    while(t--)
    {
        cin>>n;
        two = fin(n,2);
        five = fin(n,5);
        res = min(two,five);
        cout<<res<<endl;
    }
    return 0;
}
