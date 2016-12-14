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
int n,a[100005];
int bin(int x)
{
    int low=0,high=n-1;
    while(low<high-1)
    {
        int mid = (low+high)/2;
        if(a[mid]>=x)high = mid-1;
        else if(a[mid]<x&&a[mid+1]>=x)return mid;
        else low = mid+1;
    }
    if(a[high]<x)return high;
    if(a[low]<x)return low;
    return -1;
}
int main()
{
    cin>>n;
    rep(i,0,n)cin>>a[i];
    sort(a,a+n);
    int q;
    cin>>q;
    while(q--)
    {
        int x;
        cin>>x;
        int res = bin(x);
        if(res==-1)cout<<0<<endl;
        else cout<<res+1<<endl;
    }
    return 0;
}
