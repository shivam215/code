#include <bits/stdc++.h>
#define scanint(x) scanf("%d",&x)
#define scanll(x) scanf("%lld",&x)
#define scanthree(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define piii pair<pii,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
#define F first
#define S second
using namespace std;
int dp[10004];
bool comp(piii a, piii b)
{
    return a.F.S<b.F.S;
}
int main()
{
    int t;
    vector< piii > vec;
    scanint(t);
    while(t--)
    {
        int n;
        scanint(n);
        if(n==0)
        {
            cout<<0<<endl;
            continue;
        }
        vec.clear();
        for(int i=0;i<n;i++)
        {
            int a,b,c;
            scanthree(a,b,c);
            b = a+b;
            vec.push_back(mp(mp(a,b),c));
        }
        sort(vec.begin(),vec.end(),comp);
        dp[0] = vec[0].S;
        for(int i=1;i<n;i++)
        {
            dp[i] = vec[i].S;
            for(int j=0;j<=i-1;j++)
            {
                if(vec[i].F.F>=vec[j].F.S)
                {
                    dp[i] = max(dp[i],dp[j]+vec[i].S);
                }
            }
        }
        int res=0;
        for(int i=0;i<n;i++)res = max(res,dp[i]);
        printf("%d\n",res);
    }
    return 0;
}
