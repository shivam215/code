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
string s1,s2;
int rec(int i,int j)
{
    if(i==s1.size()||j==s2.size())return 0;
    int res=0;
    if(s1[i]==s2[j])res=max(res,1+rec(i+1,j+1));
    return res;
}
int main()
{
    cin>>s1>>s2;
    int res=0;
    rep(i,0,s1.size())rep(j,0,s2.size())res=max(res,rec(i,j));
    cout<<res<<endl;
    return 0;
}
