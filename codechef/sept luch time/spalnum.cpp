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
int palin[100005];
int ispalin(int n)
{
    string s;
    while(n>0)
    {
        s = s + (char)(n%10+'0');
        n = n/10;
    }
    string s1 = s;
    reverse(s1.begin(),s1.end());
    if(s1==s)return 1;
    return 0;
}
int main()
{
    int t;
    scano(t);
    rep(i,1,100005)
    {
        if(ispalin(i))palin[i]=1;
    }
    while(t--)
    {
        int l,r;
        scant(l,r);
        ll sum=0;
        for(int i=l;i<=r;i++)
        {
            if(palin[i])sum+=i;
        }
        printf("%lld\n",sum);
    }
    return 0;
}
