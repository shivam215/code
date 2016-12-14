#include <bits/stdc++.h>
#define inf 100000000
#define scanint(x) scanf("%d",&x)
#define scanll(x) scanf("%lld",&x)
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int prime[100005];
int vis[100005];
map<string,int> ans;
string s1;
void sieve()
{
    for(int i=1;i<100005;i++)prime[i]=1;
    for(int i=2;i*i<100005;i++)
    {
        if(prime[i]==1)
        {
            for(int j=i*i;j<100005;j+=i)
            {
                prime[j]=0;
            }
        }
    }
}
int convert(string s)
{
    int res = 0;
    for(int i=0;i<s.size();i++)
    {
        res = res*10 + s[i]-'0';
    }
    return res;
}
void solve(string s)
{
    queue<string> q;
    q.push(s);
    vis[convert(s)]=1;
    ans[s]=0;
    while(!q.empty())
    {
        string st = q.front();
        if(st==s1)break;
        q.pop();
        for(int i=0;i<st.size();i++)
        {
                for(int j=0;j<10;j++)
                {
                    if(i==0&&j==0)continue;
                    string str = st;
                    str[i] = (char)(j+'0');
                    int num = convert(str);
                    if(!vis[num] && prime[num])
                    {
                        ans[str] = ans[st]+1;
                        q.push(str);
                        vis[num]=1;
                    }
                }
        }
    }
}
int main()
{
    int t;
    string s;
    cin>>t;
    sieve();
    while(t--)
    {
        cin>>s>>s1;
        ans.clear();
        memset(vis,0,sizeof(vis));
        solve(s);
        map<string,int>::iterator it;
        it = ans.find(s1);
        if(it!=ans.end())cout<<ans[s1]<<endl;
        else cout<<"Impossible"<<endl;
    }
    return 0;
}
