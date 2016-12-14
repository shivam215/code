#include <bits/stdc++.h>
#define scanint(x) scanf("%d",&x)
#define scanll(x) scanf("%lld",&x)
#define pb push_back
#define mp make_pair
#define ll unsigned long long
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
vector<ll> vec;
int b1,b2;
ll convert(string str,int mainlen)
{
    ll ans=0;
    for(int i=0;i<mainlen;i++)
    {
        ans = ans*b1 + str[i]-'0';
    }
    return ans;
}
int check(ll n,int base)
{
    string str;
    while(n>0)
    {
        str = str + (char)((n%base)+'0');
        n = n/base;
    }
    string temp = str;
    reverse(str.begin(),str.end());
    if(temp==str)return 1;
    else return 0;
}
void rec(string str,int in,int len,int mainlen)
{
    if(len==0)
    {
        ll num = convert(str,mainlen);
        if(!check(num,b1))return;
        if(num<=(1LL<<60))
        {
            if(check(num,b2))vec.push_back(num);
            return;
        }
    }
    if(len==1)
    {
        for(int i=0;i<b1;i++)
        {
            str[in] = (char)(i+'0');
            rec(str,in+1,len-1,mainlen);
        }
    }
    else
    {
        for(int i=0;i<b1;i++)
        {
            str[in] = (char)(i+'0');
            str[in+len-1] = (char)(i+'0');
            rec(str,in+1,len-2,mainlen);
        }
    }

}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>b1>>b2;
        if(b1>b2)swap(b1,b2);
        int mx = 60/(log2(b1));
        string str;
        vec.clear();
        for(int i=1;i<=mx;i++)
        {
            str.resize(i);
            rec(str,0,i,i);
        }
        sort(vec.begin(),vec.end());
        vec.erase(unique(vec.begin(),vec.end()),vec.end());
        for(int i=0;i<vec.size()&&i<1000;i++)
        {
            cout<<vec[i]<<' ';
        }
        cout<<endl;
    }
    return 0;
}
