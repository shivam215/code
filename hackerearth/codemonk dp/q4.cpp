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
    ll l,r,coun;
    cin>>t;
    while(t--)
    {
        cin>>l>>r;
        coun=0;
        if(1>=l && r<=r)coun=1;
        if(r<10)
        {
            cout<<coun<<endl;
            continue;
        }
        if(l<10)l=10;
        coun = coun + (r-l+2)/2;
        cout<<coun<<endl;

    }
    return 0;
}
