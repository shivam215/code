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
int a[100005];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    int mx=1,cur=1;
    for(int i=0;i<n-1;i++)
    {
        if(a[i+1]>=a[i])
        {
            cur++;
            mx=max(mx,cur);
        }
        else
        {
            cur=1;
        }
    }
    mx = max(mx,cur);
    cout<<mx<<endl;
    return 0;
}

