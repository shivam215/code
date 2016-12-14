priority_queue<pii,vector<pii>,greater<pii> > q;
void dijkstra(int src)
{
    for(int i=0;i<MAX;i++)dis[i]=inf;
    dis[src]=0;
    q.push(mp(0,src));
    while(!q.empty())
    {
        int u = q.top().se;
        int ucost = q.top().fe;
        q.pop();
        if(ucost>dis[u])continue;
        for(int i=0; i<adj[u].size(); i++)
        {
            int v=adj[u][i].fe, vcost=adj[u][i].se;
            if(dis[v]>dis[u]+vcost)
            {
                dis[v]=dis[u]+vcost;
                q.push(mp(dis[v],v));
            }
        }

    }
}
