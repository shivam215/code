#include <bits/stdc++.h>
#define inf 1000000000
#define mod 100003
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
#define MAX 100005
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        ll ans=0,cur=0,prev=0;
        rep(i,0,s.size())
        {
            if(s[i]=='0')cur = prev;
            else cur = prev+1;
            if(((s[i]-'0')%2)==0)ans = ans + cur;
            if(s[i]=='0')ans++;
            prev = cur;
        }
        cout<<ans<<endl;
    }
    return 0;

}
