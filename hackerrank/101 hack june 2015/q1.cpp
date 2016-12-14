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
int a[26];
int main()
{
    string st;
    cin>>st;
    rep(i,0,st.size())a[st[i]-'a']++;
    set<int> s;
    rep(i,0,26)
    {
        if(a[i]!=0)s.insert(a[i]);
    }
    int flag=0;
    if(s.size()==1)flag=1;
    else
    {
        rep(i,0,26)
        {
            s.clear();
            if(a[i]==0)continue;
            rep(j,0,26)
            {
                if(j==i)
                {
                    if(a[i]-1!=0)s.insert(a[i]-1);
                }
                else
                {
                    if(a[j]!=0)s.insert(a[j]);
                }
            }
            if(s.size()==1)
            {
                flag=1;
                break;
            }
        }
    }
    if(flag)printf("YES\n");
    else printf("NO\n");
    return 0;
}
