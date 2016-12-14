#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ifend 27
#define precoun 28
using namespace std;
int trie[1000][30];
void insert_trie(string s)
{
    static int cnt=1;
    int cur=0;
    int k=0;
    while(trie[cur][s[k]-'a']!=0)
    {
        cur = trie[cur][s[k]-'a'];
        trie[cur][precoun]+=1;
        k++;
        if(k>=s.size())break;
    }
    if(k==s.size())
    {
        trie[cur][ifend]+=1;
    }
    else
    {
        while(k<s.size())
        {
            trie[cur][s[k]-'a']=cnt;
            cur = cnt;
            trie[cur][precoun]+=1;
            k++;cnt++;
        }
        trie[cur][ifend]+=1;
    }
}
int search_trie(string s)
{
    int cur=0;
    rep(i,0,s.size())
    {
        if(trie[cur][s[i]-'a']==0)return 0;
        cur = trie[cur][s[i]-'a'];
    }
    return (trie[cur][ifend]>=1);
}
int prefix_count(string s)
{
    int cur=0;
    rep(i,0,s.size())
    {
        if(trie[cur][s[i]-'a']==0)return 0;
        cur = trie[cur][s[i]-'a'];
    }
    return trie[cur][precoun];
}
int main()
{
    while(true)
    {
        string s,s1;
        cin>>s;
        if(s=="insert")
        {
            cin>>s1;
            insert_trie(s1);
        }
        if(s=="search")
        {
            cin>>s1;
            cout<<search_trie(s1)<<endl;
        }

        if(s=="count")
        {
            cin>>s1;
            cout<<prefix_count(s1)<<endl;

        }
    }
    return 0;

}
