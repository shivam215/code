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
using namespace std;
set<int> ans;
int mx,n;
int sum[105],a[105];
void solve(int i,vector<int> vec)
{
    if(i>=n+1)
    {
        int cur=0;
        rep(i,0,vec.size())
        {
            cur = max(cur,vec[i]);
        }
        if(cur>mx)
        {
            ans.clear();
            mx = cur;
        }
        rep(i,0,100005)
        {
            if(vec[i]==mx)
            {
                ans.insert(i);
            }
        }
        return;
    }
    for(int j=i;j<=n;j++)
    {
        vector<int> v = vec;
        v[sum[j]-sum[i-1]]++;
        solve(j+1,v);
    }
}
int main()
{
    scano(n);
    rep(i,1,n+1)
    {
        scano(a[i]);
        sum[i] = sum[i-1] + a[i];
    }
    vector<int> vec(100005,0);
    solve(1,vec);
    printf("%d\n",mx);
    set<int>::iterator it;
    for(it=ans.begin();it!=ans.end();it++)
    {
        printf("%d ",(*it));
    }
    printf("\n");
    return 0;
}
