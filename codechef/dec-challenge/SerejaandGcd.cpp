#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll fastexpmod(ll a, ll b, ll c){ll x=1,y=a;while(b>0){if(b&1)x=(x*y)%c;y=(y*y)%c;b>>=1;}return x%c;}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    int T,N,M,L,R,i,j;
    ll mod = 1000000007,sum;
    cin>>T;
    while(T--)
    {
        cin>>N>>M>>L>>R;
        sum = 0;
        if(L==1)
        {
            sum = fastexpmod(M,N,mod);
            cout<<sum<<endl;
            continue;
        }
        for(j=L;j<=R;j++)
        {
            sum = (sum + fastexpmod(M/j,N,mod))%mod;
            for(i=2*j;i<=M;i=i+j)
            {
                sum = (sum - fastexpmod(M/i,)
            }
        }

        cout<<sum<<endl;
    }
    return(0);
}
