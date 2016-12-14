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
int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    ll MAX=n;
    rep(i,1,n+1)MAX*=i;
    int k1;
    cin>>k1;
    queue<int> st1,st2;
    rep(i,0,k1)
    {
        int temp;
        cin>>temp;
        st1.push(temp);
    }
    int k2;
    cin>>k2;
    rep(i,0,k2)
    {
        int temp;
        cin>>temp;
        st2.push(temp);
    }
    ll cnt=0;
    while(!st1.empty()&&!st2.empty()&&cnt<=MAX)
    {
        int c = st1.front();
        int d = st2.front();
        st1.pop();st2.pop();
        if(c>d)
        {
            st1.push(d);
            st1.push(c);
        }
        else
        {
            st2.push(c);
            st2.push(d);
        }
        cnt++;
    }
    if(st1.empty()||st2.empty())
    {
        int ans=2;
        if(st2.empty())ans=1;
        printf("%lld %d\n",cnt,ans);
    }
    else printf("-1\n");
    return 0;
}
