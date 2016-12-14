#include <bits/stdc++.h>
#define inf 1000000000
#define mod 1000000007
#define scano(x) scanf("%d",&x)
#define scanll(x) scanf("%lld",&x)
#define scant(x,y) scanf("%d%d",&x,&y)
#define pb push_back
#define mp make_pair
#define ll unsigned long long
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fe first
#define se second
using namespace std;
string solve(ll n,ll m)
{
    string s1,s2;
    while(n>0)
    {
        s1 = s1 + (char)(n%10+'0');
        n/=10;
    }
    while(m>0)
    {
        s2 = s2 + (char)(m%10+'0');
        m/=10;
    }
    if(s1.size()>s2.size())
    {
        int diff = s1.size()-s2.size();
        while(diff--)
        {
            s2 = s2 + '0';
        }
    }
    else
    {
        int diff = s2.size()-s1.size();
        while(diff--)
        {
            s1 = s1 + '0';
        }
    }
    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());
    string ans;
    int flag=0;
    rep(i,0,s1.size())
    {
        if(flag)
        {
            ans = ans + '9';
            continue;
        }
        int a = s1[i]-'0' + s2[i]-'0';
        if(a>9)
        {
            a=9;
            flag=1;
        }
        ans = ans + (char)(a+'0');
    }
    return ans;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        cout<<solve(n,m)<<"\n";
    }
    return 0;
}
