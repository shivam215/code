#include <bits/stdc++.h>
#define MAX 100005
#define scano(x) scanf("%d",&x)
#define scant(x,y) scanf("%d%d",&x,&y)
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int vis[MAX],dis[MAX];
vector<int> pos[10];
int main()
{
    string s;
    cin>>s;
    int n =  s.size();
    rep(i,0,n)
    {
        pos[(int)(s[i])-'0'].pb(i);
    }
    queue<int> q;
    q.push(0);
    memset(dis,0,sizeof(dis));
    memset(vis,0,sizeof(vis));
    vis[0]=1;
    while(!q.empty())
    {
        int fr = q.front();
        if(fr==n-1)break;
        q.pop();
        if(fr+1<n)
        {
            if(!vis[fr+1])
            {
                vis[fr+1]=1;
            q.push(fr+1);
            dis[fr+1]=dis[fr]+1;
            }
        }
        if(fr-1>=0)
        {
            if(!vis[fr-1])
            {
                vis[fr-1]=1;
            q.push(fr-1);
            dis[fr-1] = dis[fr]+1;
            }
        }
        rep(i,0,pos[s[fr]-'0'].size())
        {
            int in = pos[s[fr]-'0'][i];
            if(!vis[in])
            {
                vis[in]=1;
            q.push(in);
            dis[in] = dis[fr]+1;
            }
        }
        pos[s[fr]-'0'].clear();
    }
    printf("%d\n",dis[n-1]);
    return 0;
}
