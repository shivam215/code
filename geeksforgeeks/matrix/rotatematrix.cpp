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
int a[10][10];
int main()
{
    int n,m;
    cin>>n>>m;
    rep(i,0,n)rep(j,0,m)cin>>a[i][j];
    rep(i,0,n/2)
    {
        rep(j,0,m/2)
        {
            int temp = a[i][j];
            a[i][j] = a[n-1-j][i];
            a[n-1-j][i] = a[n-1-i][n-1-j];
            a[n-1-i][n-1-j] = a[j][n-1-i];
            a[j][n-1-i] = temp;
        }
    }
    rep(i,0,m){rep(j,0,n)cout<<a[i][j]<<' ';cout<<endl;}
}
