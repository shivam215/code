/*spoj problem keytask */
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
int dis[105][105][16];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int n,m;
int ingrid(pii &a)
{
    if(a.first>=0 && a.first<n && a.second>=0 && a.second<m)
    {
        return 1;
    }
    return 0;
}
int main()
{
    string s[105];
    while(1)
    {
        cin>>n>>m;
        if(n==0&&m==0)break;

        rep(i,0,n)cin>>s[i];
        int i,j;
        int flag=0;
        for(i=0;i<n;i++)
        {
        for(j=0;j<m;j++)
        {
            if(s[i][j]=='*'){flag=1;break;}
        }
        if(flag)break;
        }

        queue<pair<pii,int> > q;

        memset(dis,-1,sizeof(dis));
        while(!q.empty())q.pop();

        q.push(mp(mp(i,j),0));
        dis[i][j][0]=0;
        int res=-1;
        while(!q.empty())
        {
            pii u = q.front().first;
            int umask = q.front().second;
            //cout<<u.first<<' '<<u.second<<' '<<umask<<endl;
            if(s[u.first][u.second]=='X')
            {
                res = dis[u.first][u.second][umask];
                break;
            }
            q.pop();
            for(i=0;i<4;i++)
            {
                pii v = mp(u.first+dx[i],u.second+dy[i]);
                int vmask = umask;
                if(ingrid(v))
                {
                    if(s[v.first][v.second]=='#')continue;
                    if(s[v.first][v.second]=='.'||s[v.first][v.second]=='X'||s[v.first][v.second]=='*')
                    {
                        if(dis[v.first][v.second][vmask]==-1)
                        {
                            dis[v.first][v.second][vmask] = dis[u.first][u.second][umask]+1;
                            q.push(mp(v,vmask));
                        }
                    }
                    else if(islower(s[v.first][v.second]))
                    {
                        if(dis[v.first][v.second][vmask]==-1)
                        {
                        switch(s[v.first][v.second])
                        {
                            case 'b':vmask|=1;break;
                            case 'y':vmask|=2;break;
                            case 'r':vmask|=4;break;
                            case 'g':vmask|=8;break;
                        }


                        dis[v.first][v.second][vmask] = dis[u.first][u.second][umask]+1;
                        q.push(mp(v,vmask));
                        }

                    }
                    else if(isupper(s[v.first][v.second]))
                    {
                        if(dis[v.first][v.second][vmask]==-1)
                        {


                        switch(s[v.first][v.second])
                        {

                            case 'B':if(vmask&1)q.push(mp(v,vmask));break;
                            case 'Y':if(vmask&2)q.push(mp(v,vmask));break;
                            case 'R':if(vmask&4)q.push(mp(v,vmask));break;
                            case 'G':if(vmask&8)q.push(mp(v,vmask));break;

                        }
                        dis[v.first][v.second][vmask] = dis[u.first][u.second][umask]+1;
                        }

                    }


                }
            }
        }
        if(res==-1)printf("The poor student is trapped!\n");
        else printf("Escape possible in %d steps.\n", res);

    }
    return 0;
}

