#include <bits/stdc++.h>
#define inf 1000000000
#define mod 1000000007
#define scano(x) scanf("%d",&x)
#define scanll(x) scanf("%lld",&x)
#define scant(x,y) scanf("%d%d",&x,&y)
#define pb push_back
#define mp make_pair
#define ll long long int
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fe first
#define se second
using namespace std;
int a[15];
int makenum(string s)
{
    int res=0;
    for(int i=0;i<s.size();i++)
    {
        res = res*10 + s[i]-'0';
    }
    return res;
}
string makes(int num)
{
    string s;
    while(num>0)
    {
        s = s + (char)(num%10 +'0');
        num/=10;
    }
    return s;
}
int rec(int n)
{
    if(n==0)return 0;
    int n1 = n;
    string s = makes(n);
    sort(s.begin(),s.end());
    int n2 = makenum(s);
    return 1+rec(n1-n2);
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        rep(i,0,n)cin>>a[i];
        int res=0;
        for(int i=0;i<n;i++)
        {
            res = max(res,rec(a[i]));
        }
        printf("%d\n",res);

    }
    return 0;
}
