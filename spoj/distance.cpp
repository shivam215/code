#include <bits/stdc++.h>
#define scano(x) scanf("%d",&x)
#define scant(x,y) scanf("%d%d",&x,&y)
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
    int n,d,a[64],mx[64],mn[64];
    cin>>n>>d;
    for(int i=0;i<64;i++)
    {
        mx[i] = INT_MIN;
        mn[i] = INT_MAX;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<d;j++)
        {
            cin>>a[j];
        }
        for(int mask=0;mask<(1<<d);mask++)
        {
            int sum=0;
            for(int i=0;i<d;i++)
            {
                if(mask&(1<<i))sum = sum + a[i];
                else sum = sum - a[i];
            }
            mx[mask] = max(mx[mask],sum);
            mn[mask] = min(mn[mask],sum);
        }
    }
    int res=INT_MIN;
    for(int i=0;i<(1<<d);i++)
    {
        res = max(res,mx[i]-mn[i]);
    }
    cout<<res<<endl;
    return 0;

}
