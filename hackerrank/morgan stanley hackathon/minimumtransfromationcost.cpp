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
int a,b,c;
int d[26],e[26];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>s1>>s2>>a>>b>>c;
        memset(d,0,sizeof(d));
        memset(e,0,sizeof(e));
        rep(i,0,s1.size())d[s1[i]-'a']++;
        rep(i,0,s2.size())e[s2[i]-'a']++;
        int cost = min(a+b,c);
        int ans=0;
        if(s1.size()>=s2.size())
        {
            int diff=0;
            rep(i,0,26)
            {
                diff = diff + abs(d[i]-e[i]);
            }
            diff = diff-(s1.size()-s2.size());
            ans = ans + a*(s1.size()-s2.size());
            diff = diff/2;
            ans = ans + cost*diff;
        }
        else
        {
            int diff=0;
            rep(i,0,26)diff=diff+abs(d[i]-e[i]);
            diff = diff-(s2.size()-s1.size());
            ans = ans + b*(s2.size()-s1.size());
            diff = diff/2;
            ans = ans + cost*diff;
        }
        cout<<ans<<endl;
    }
    return 0;
}
