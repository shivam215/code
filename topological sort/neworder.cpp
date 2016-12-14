#include <bits/stdc++.h>
#define pb push_back
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
typedef long long ll;
int a[26],vis[26];
int g[26][26];
vector < vector < int > > ans;
stack<int> st;
void topo(int root)
{
    vis[root]=1;
    rep(i,0,26)
    {
        if(g[root][i] && !vis[i])topo(i);
    }
    st.push(root);
}
void toposort()
{
    int count[26]={};
    vector < int > cur;
    for(int i=0; i<26; i++)
    {
        int flag=0;
        for(int j=0; j<26; j++)
            if(g[j][i])flag=1,count[i]++;
        if(flag==0)
            cur.pb(i);
    }
    while(1)
    {
        vector < int > ncur;
        if(cur.empty())break;
        ans.pb(cur);
        for(int i=0; i<cur.size(); i++)
            for(int j=0; j<26; j++)
                if(g[cur[i]][j])
                {
                    g[cur[i]][j]=0,count[j]--;
                    if(count[j]==0)ncur.pb(j);
                }
        cur.clear();
        for(int i=0; i<ncur.size(); i++)
            cur.pb(ncur[i]);
    }
}
int main()
{
    int n,coun[26];
    string s[102];
    cin>>n;
    rep(i,0,n){cin>>s[i];rep(j,0,s[i].size())a[s[i][j]-'a']=1;}
    if(n==1)
    {
        sort(s[0].begin(),s[0].end());
        cout<<s[0]<<endl;
        return 0;
    }
    rep(i,0,n)
    {
        rep(j,i+1,n)
        {
            for(int k=0; k<s[i].size(),k<s[j].size(); k++)
            {
                if(s[i][k]!=s[j][k])
                {
                    g[s[i][k]-'a'][s[j][k]-'a']=1;
                    break;
                }
            }
        }
    }
    toposort();
    for(int i=0; i<ans.size(); i++,cout<<endl)
    {
        sort(ans[i].begin(),ans[i].end());
        for(int j=0; j<ans[i].size(); j++)
            if(a[ans[i][j]])
                cout << (char)(ans[i][j]+'a');
    }
    return 0;
}


