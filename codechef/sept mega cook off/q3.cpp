#include <bits/stdc++.h>
#define inf 1000000000
#define mod 1000000007
#define scano(x) scanf("%d",&x)
#define scanll(x) scanf("%lld",&x)
#define scant(x,y) scanf("%d%d",&x,&y)
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fe first
#define se second
#define mx 1000000000000000000LL
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll a,b;
        cin>>a>>b;
        ll cnt=0;
        ll tmp=1;
        for(int i=1;i<=60;i++)
        {
            tmp*=2;
            if(tmp>=a&&tmp<=b)cnt++;
            ll c = tmp;
            for(int j=1;j<=38;j++)
            {
                c = c*3;
                if(c>mx)break;
                if(c>=a&&c<=b)cnt++;
            }
            if(tmp>mx)break;
        }
        if(1>=a&&1<=b)cnt++;
        cout<<cnt<<endl;

    }
    return 0;
}
