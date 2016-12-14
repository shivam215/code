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
pii a[1003];
int l[1003];
bool comp(pii x, pii y)
{
    if(x.first!=y.first)return x.first<y.first;
    else return x.second<y.second;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        rep(i,0,n)cin>>a[i].second;
        rep(i,0,n)cin>>a[i].first;
        sort(a,a+n,comp);
        l[0]=1;
        for(int i=1;i<n;i++)
        {
            l[i]=1;
            for(int j=0;j<i;j++)
            {
                if(a[i].second>=a[j].second)
                {
                    l[i] = max(l[i],1+l[j]);
                }
            }
        }
        int res=0;
        for(int i=0;i<n;i++)res=max(res,l[i]);
        cout<<res<<endl;
    }
    return 0;
}
