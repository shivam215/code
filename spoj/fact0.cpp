#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
void primefactor(ll n)
{
    ll cnt=0;
    while(n%2==0)
    {
        n = n/2;
        cnt++;
    }
    if(cnt>0)cout<<"2^"<<cnt<<' ';
    for(ll i=3;i*i<=n;i+=2)
    {
        cnt=0;
        while(n%i==0)
        {
            n = n/i;
            cnt++;
        }
        if(cnt>0)cout<<i<<"^"<<cnt<<' ';
    }
    if(n>1)cout<<n<<"^"<<1<<' ';
    cout<<endl;
}
int main()
{
    ll n;
    while(1)
    {
        cin>>n;
        if(n==0)break;
        primefactor(n);
    }
    return 0;
}
