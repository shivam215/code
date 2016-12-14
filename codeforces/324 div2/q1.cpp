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
map<pii,string> m;
int n,t;
string solve(int i,int j,string s)
{
    if(i==n)
    {
        if(j==0)return s;
        return " ";
    }
    if(m.find(mp(i,j))!=m.end())return m[mp(i,j)];
    int st;
    if(i==0)st=1;
    else st=0;
    for(int k=st;k<=9;k++)
    {
        int rem = (j*10 + k)%t;
        string str = solve(i+1,rem,s+(char)(k+'0'));
        if(str!=" ")return m[mp(i,j)] = str;
    }
    return m[mp(i,j)] = " ";
}
int main()
{
    cin>>n>>t;
    string str = solve(0,0,"");
    if(str==" ")cout<<-1<<endl;
    else cout<<str<<endl;
    return 0;
}
