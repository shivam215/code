#include <bits/stdc++.h>
using namespace std;
int parent[2003];
int main()
{
    int n,e,flag,t;
    vector< pair<int,int> > edge;
    cin>>t;
    for(int test=1;test<=t;test++)
    {
        edge.clear();
        flag=0;
    cin>>n>>e;
    for(int i=0;i<e;i++)
    {
        int a,b;
        cin>>a>>b;
        edge.push_back(make_pair(a,b));
    }
    memset(parent,-1,sizeof(parent));
    for(int i=0;i<edge.size();i++)
    {
        int a = edge[i].first;
        int b = edge[i].second;
        int aroot = fin(a);
        int broot = fin(b);
        if(aroot==broot)flag=1;
        else unio(aroot,broot);
    }
    cout<<"Scenario #"<<test<<":"<<endl;
    if(flag)cout<<"Suspicious bugs found!"<<endl;
    else cout<<"No suspicious bugs found!"<<endl;
    }
    return 0;

}
