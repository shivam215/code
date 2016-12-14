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
int dx[] = {-1,1,-2,2,-2,2,-1,1};
int dy[] = {-2,-2,-1,-1,1,1,2,2};
int dis[10][10],x,y;
int isvalid(pii &v)
{
    if(v.first>=0 && v.first<8 && v.second>=0 && v.second<8)return 1;
    return 0;
}
void bfs(string s)
{
    queue< pii > q;
    while(!q.empty())q.pop();
    q.push(mp(s[1]-'0'-1,s[0]-'a'));
    dis[s[1]-'0'-1][s[0]-'a']=0;
    while(!q.empty())
    {
        pii u = q.front();
        q.pop();
        if(u.first==x && u.second==y)break;
        for(int i=0;i<8;i++)
        {
            pii v = mp(u.first+dx[i],u.second+dy[i]);
            if(isvalid(v))
            {
                if(dis[v.first][v.second]==-1)
                {
                    q.push(v);
                    dis[v.first][v.second]=dis[u.first][u.second]+1;
                }
            }
        }
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a,b;
        cin>>a>>b;
        x = b[1]-'0'-1;
        y = b[0]-'a';
        memset(dis,-1,sizeof(dis));
        bfs(a);
        cout<<dis[x][y]<<endl;
    }
    return 0;
}
