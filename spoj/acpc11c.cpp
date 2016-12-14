#include <bits/stdc++.h>
#define inf 1000000000000000LL
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
int a[100005];
ll cum[100005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        ll sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            sum+=a[i];
            if(i==0)cum[i]=a[0];
            else cum[i] = cum[i-1]+a[i];
        }
        ll mn=inf;
        for(int i=0;i<n;i++)
        {
            ll temp;
            if(i==0||i==n-1)temp = sum-a[i];
            else
            {
                temp = min(2*cum[i-1]+sum-cum[i],cum[i-1]+2*(sum-cum[i]));
            }
            if(mn>temp)mn=temp;
        }
        cout<<mn<<endl;
    }
    return 0;
}
