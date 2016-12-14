#include <bits/stdc++.h>
#define scano(x) scanf("%d",&x)
#define mod 1000000007
#define scant(x,y) scanf("%d%d",&x,&y)
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
ll solve(ll n)
{
    if(n==0)return 0;
    if(n==1||n==2)return 1;
    ll temp = n-1;
    ll res=0;
    for(ll i=1;i*i<=temp;i++)
    {
        if(temp%i==0)
        {
            if(i*i==temp)
            {
                if(i!=1)
                {
                    res = (res + i*solve(temp/i))%mod;
                }
            }
            else
            {
                if(i!=1)
                {
                    res = (res + i*solve(temp/i))%mod;
                }
                if((temp/i)!=1)
                {
                    res = (res + (temp/i)*solve(i))%mod;
                }
            }
        }
    }
    return res;
}
int main()
{
    ll n;
    cin>>n;
    ll res = solve(n);
    cout<<res<<endl;
    return 0;
}
