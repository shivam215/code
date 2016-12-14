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
    int n,k,x,ans,t;
    vi v;
    cin>>t;
    while(t--)
    {
        v.clear();
        cin>>n>>k;
        rep(i,0,n)
        {
            cin>>x;
            ans=0;
            rep(j,0,20)
            {
                if(x & 1<<j)
                {
                    ans++;
                }
            }

            v.pb(ans);


        }
        sort(v.rbegin(),v.rend());
        int fa=0;
        rep(i,0,k)
        fa=fa+v[i];

        cout<<fa<<"\n";
    }
    return 0;
}
