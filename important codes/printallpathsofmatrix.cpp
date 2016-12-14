#include <bits/stdc++.h>
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
typedef long long ll;
int a[20][20],n;
vector<int> path;
void f(int i, int j)
{
    path.push_back(a[i][j]);
    if(i==n && j==n)
    {
        rep(k,0,path.size())cout<<path[k]<<' ';
        cout<<endl;
    }
    if((i+1)<=n){f(i+1,j);}
    if(j+1<=n)f(i,j+1);
    path.pop_back();
}
int main()
{
    cin>>n;
    rep(i,1,n+1)rep(j,1,n+1)cin>>a[i][j];
    f(1,1);
}

