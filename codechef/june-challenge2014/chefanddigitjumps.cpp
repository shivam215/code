#include <bits/stdc++.h>
using namespace std;
bool vis[100004];
int d[100004];
vector<int> v[10];
queue<int> q;
int main()
{
    ios_base::sync_with_stdio(false);
    string s;
    cin>>s;
    memset(vis,false,sizeof vis);
    int sz = s.size();
    for(int i=0;i<sz;i++)
    {
        v[s[i]-'0'].push_back(i);
    }
    vis[0]=true;d[0]=0;q.push(0);
    while(!q.empty())
    {
        int idx = q.front();
        if(idx==sz-1)
            break;
        q.pop();
        int val = s[idx]-'0';
        int vsz = v[val].size();

        for(int i=0;i<vsz;i++)
        {
            int nidx = v[val][i];
            if(!vis[nidx])
            {
                vis[nidx]=true;
                d[nidx] = d[idx]+1;
                q.push(nidx);
            }
        }
        v[val].clear();
        if(idx-1>=0 && !vis[idx-1])
        {
            vis[idx-1]=true;
            d[idx-1] = d[idx]+1;
            q.push(idx-1);
        }
        if(idx+1<sz && !vis[idx+1])
        {
            vis[idx+1]=true;
            d[idx+1] = d[idx]+1;
            q.push(idx+1);
        }

    }
    cout<<d[sz-1]<<endl;
    return 0;

}
