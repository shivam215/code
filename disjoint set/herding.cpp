#include <bits/stdc++.h>
#define inf 100000000
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
using namespace std;
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
map<char,int> ma;
pii parent[1003][1003];
string s[1003];
pii fin(pii i)
{
    if(parent[i.first][i.second]==i)return i;
    return fin(parent[i.first][i.second]);
}
void unio(pii a, pii b)
{
    pii x = fin(a);
    pii y = fin(b);
    if(x==y)return;
    else parent[x.first][x.second]=y;
}
int main()
{
    int n,m;
    scant(n,m);
    rep(i,0,n)cin>>s[i];
    ma['E']=0;ma['W']=1;ma['N']=2;ma['S']=3;
    rep(i,0,n)rep(j,0,m)parent[i][j] = mp(i,j);
    rep(i,0,n)
    {
        rep(j,0,m)
        {
            int temp = ma[s[i][j]];
            int a = i + dx[temp];
            int b = j + dy[temp];
            unio(mp(i,j),mp(a,b));
        }
    }
    int cnt=0;
    rep(i,0,n)rep(j,0,m)if(parent[i][j]==mp(i,j))cnt++;
    cout<<cnt<<endl;
    return 0;

}
