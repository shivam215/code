#include <bits/stdc++.h>
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define ifend 2
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
typedef long long ll;
int a[20][20],n;
vector<int> xors[2][20];
int trie[1000006][4],cnt;
void calc(int ix)
{
    rep(i,0,1<<(n-1))
    {
        int row=0,column=0,dx=1;
        if(ix==1){row=n-1;column=n-1;dx=-1;}
        int res = a[row][column];
        for(int j=n-2;j>=0;j--)
        {
            if(i&(1<<j))row+=dx;
            else column+=dx;
            res = res^a[row][column];
        }
        if(ix==1)res = res^a[row][column];
        xors[ix][row].push_back(res);
    }
    rep(i,0,n)
    {
        sort(xors[ix][i].begin(),xors[ix][i].end());
        int sz = unique(xors[ix][i].begin(),xors[ix][i].end())-xors[ix][i].begin();
        xors[ix][i].resize(sz);
    }
}
void insert_trie(int x)
{
    int cur=0;
    int k=18;
    while(trie[cur][x&(1<<k)]!=0)
    {
        cur = trie[cur][x&(1<<k)];
        k--;
        if(k<0)break;
    }
    if(k<0)
    {
        trie[cur][ifend]=1;
    }
    else
    {
        while(k>=0)
        {
            trie[cur][x&(1<<k)]=cnt;
            cur = cnt;
            k--;cnt++;
        }
        trie[cur][ifend]+=1;
    }
}
void build_trie(int i)
{
    rep(j,0,xors[0][i].size())
    {
        insert_trie(xors[0][i][j]);
    }
}
int search_trie(int x)
{
    int mx=0,cur=0;
    for(int i=18;i>=0;i--)
    {
        int bit = x&(1<<i);
        if(trie[cur][1-bit]!=0)
        {
            mx = mx|(1<<i);
            cur = trie[cur][1-bit];
        }
        else
        {
            cur = trie[cur][bit];
        }
    }
    return mx;
}
int main()
{
    cin>>n;
    rep(i,0,n)rep(j,0,n)cin>>a[i][j];
    calc(0);
    calc(1);
    int ans=0;
    rep(i,0,n)
    {
        cnt=1;
        memset(trie,0,sizeof(trie));
        build_trie(i);
        int res=0;
        rep(j,0,xors[1][i].size())
        {
            res = max(res,search_trie(xors[1][i][j]));
        }
        ans = max(ans,res);
    }
    cout<<ans<<endl;
    return 0;
}

