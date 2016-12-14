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
int a[100005],b[100005];
int main()
{
    int n,k;
    cin>>n>>k;
    rep(i,0,n)cin>>a[i];
    rep(i,0,n)cin>>b[i];
    sort(a,a+n);
    sort(b,b+n);
    int i=0,j=0,cnt=0;
    while(i<n&&j<n)
    {
        if(abs(a[i]-b[j])<=k)
        {
            cnt++;
            i++;j++;
        }
        else if(a[i]>b[j])j++;
        else i++;
    }
    cout<<cnt<<endl;
    return 0;
}
