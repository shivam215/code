#include <bits/stdc++.h>
using namespace std;
int moves[100];
int dist[100],vis[100],n;
void bfs()
{
    queue<int> q;
    q.push(0);
    vis[0]=1;
    dist[0]=0;
    while(!q.empty())
    {
        int fr = q.front();
        q.pop();
        if(fr==n-1)break;

        for(int i=1;i<=6;i++)
        {
            if(fr+i<30)
            {
                int node;
                if(moves[fr+i]!=-1)node=moves[fr+i];
                else node = fr+i;
                if(!vis[node])
                {
                    dist[node] = dist[fr]+1;
                    vis[node]=1;
                    q.push(node);
                }
            }
        }
    }

}
int main()
{
    cin>>n;
    memset(moves,-1,sizeof(moves));
    moves[2] = 21;
    moves[4] = 7;
    moves[10] = 25;
    moves[19] = 28;

    moves[26] = 0;
    moves[20] = 8;
    moves[16] = 3;
    moves[18] = 6;
    bfs();
    cout<<dist[n-1]<<endl;
}
