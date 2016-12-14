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
map<string,int> m,vis,dis;
string s,e;
void solve()
{
    dis[s]=0;
    vis[s]=1;
    queue<string> q;
    q.push(s);
    while(!q.empty())
    {
        string temp = q.front();
        q.pop();
        if(temp==e)break;
        rep(i,0,3)
        {
            string str = temp;
            str[i] = (char)(((str[i]-'a'-1+26)%26) + 'a');
            if(!vis[str]&&!m[str])
            {
                vis[str]=1;
                dis[str] = dis[temp]+1;
                q.push(str);
            }
        }
        rep(i,0,3)
        {
            string str = temp;
            str[i] = (char)((str[i]-'a'+1)%26 + 'a');
            if(!vis[str]&&!m[str])
            {
                vis[str]=1;
                dis[str]=dis[temp]+1;
                q.push(str);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>s>>e;
    cin>>n;
    rep(i,0,n)
    {
        string s1,s2,s3;
        cin>>s1>>s2>>s3;
        rep(j,0,s1.size())
        {
        rep(k,0,s2.size())
        {
        rep(l,0,s3.size())
        {
            string str;
            str = str + s1[j]+s2[k]+s3[l];
            m[str]=1;
        }
        }
        }
    }
    if(m[s]||m[e])
    {
        printf("-1\n");
        return 0;
    }
    solve();
    if(dis.find(e)!=dis.end())
    {
        printf("%d\n",dis[e]);
    }
    else
        printf("-1\n");
    return 0;
}
