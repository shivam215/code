#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
int parent1[1003],parent2[1003],ran1[1003],ran2[1003],vis[1003];
vector<int> g1[1003],g2[1003];
typedef pair< pair<int,int>,int > iii;
vector<iii> e;
void dfs1(int root)
{
    vis[root]=1;
    for(int i=0;i<g1[root].size();i++)
    {
        int child = g1[root][i];
        if(!vis[child])dfs1(child);
    }
}
void dfs2(int root)
{
    vis[root]=1;
    for(int i=0;i<g2[root].size();i++)
    {
        int child = g2[root][i];
        if(!vis[child])dfs2(child);
    }
}
int Find1(int i)
{
    if (parent1[i]!=i)
        parent1[i] = Find1(parent1[i]);
    return parent1[i];
}
void Union1(int x, int y)
{
    int xroot = Find1(x);
    int yroot = Find1(y);
    if (ran1[xroot]<ran1[yroot])
        parent1[xroot] = yroot;
    else if (ran1[xroot]>ran1[yroot])
        parent1[yroot] = xroot;
    else
    {
        parent1[yroot]=xroot;
        ran1[xroot]++;
    }
}
int Find2(int i)
{
    if (parent2[i]!=i)
        parent2[i] = Find2(parent2[i]);
    return parent2[i];
}
void Union2(int x, int y)
{
    int xroot = Find2(x);
    int yroot = Find2(y);
    if (ran2[xroot]<ran2[yroot])
        parent2[xroot] = yroot;
    else if (ran2[xroot]>ran2[yroot])
        parent2[yroot] = xroot;
    else
    {
        parent2[yroot]=xroot;
        ran2[xroot]++;
    }
}
bool comp(iii a, iii b)
{
    return a.second>b.second;
}
int main()
{
    int n,m,a,b,c,i;
    cin>>n>>m;
    for(i=0;i<m;i++)
    {
        cin>>a>>b>>c;
        if(c==3)
        {
            g1[a].push_back(b);
            g1[b].push_back(a);
            g2[a].push_back(b);
            g2[b].push_back(a);
        }
        else if(c==1)
        {
            g1[a].push_back(b);
            g1[b].push_back(a);
        }
        else if(c==2)
        {
            g2[a].push_back(b);
            g2[b].push_back(a);
        }
        e.push_back(mp(mp(a,b),c));
    }
    int flag=1;
    memset(vis,0,sizeof(vis));
    dfs1(1);
    for(i=1;i<=n;i++)if(!vis[i]){flag=0;break;}
    if(flag)
    {
        memset(vis,0,sizeof(vis));
        dfs2(1);
        for(i=1;i<=n;i++)if(!vis[i]){flag=0;break;}
    }
    if(flag==0){cout<<-1<<endl;return 0;}

    sort(e.begin(),e.end(),comp);
    memset(ran1,0,sizeof(ran1));
    memset(ran2,0,sizeof(ran2));
    for(i=1;i<1003;i++){parent1[i]=i;parent2[i]=i;}
    int merg1=0,merg2=0;
    int total = 2*n-2;
    int len = e.size();
    int res=0;
    i=0;
    //for(i=0;i<len,merg1+merg2<total;i++)
    while(merg1<n-1 || merg2<n-1)
    {
        a = e[i].first.first;
        b = e[i].first.second;
        c = e[i].second;
        //cout<<a<<b<<c<<endl;
        if(c==3)
        {
            int x1 = Find1(a);
            int y1 = Find1(b);
            int x2 = Find2(a);
            int y2 = Find2(b);
            if(x1!=y1 && x2!=y2)
            {
                res++;
                merg1++;merg2++;
                Union1(x1,y1);
                Union2(x2,y2);
            }

        }
        else if(c==1)
        {
            int x1 = Find1(a);
            int y1 = Find1(b);
            if(x1!=y1)
            {
                res++;
                merg1+=1;
                Union1(x1,y1);
            }

        }
        else
        {
            int x2 = Find2(a);
            int y2 = Find2(b);
            if(x2!=y2)
            {
                res++;
                merg2+=1;
                Union2(x2,y2);
            }

        }
        i++;

    }
    cout<<len-res<<endl;
    return 0;


}
