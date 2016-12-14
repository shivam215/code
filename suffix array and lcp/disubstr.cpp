#include <bits/stdc++.h>
#define scano(x) scanf("%d",&x)
#define scant(x,y) scanf("%d%d",&x,&y)
#define pb push_back
#define precoun 26
#define mp make_pair
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int sa[1003],lcp[1003];
string s;
void build()
{
    vector<string> v;
    map<string,int> m;
    for(int i = 0; i < s.size();i++)
    {
        m[s.substr(i,s.size()-i)] = i;
        v.push_back(s.substr(i,s.size()-i));
    }
    sort(v.begin(),v.end());
    for(int i = 0; i < v.size();i++)
    {
        sa[i] = m[v[i]];
    }
}
void compute()
{
    lcp[0]=0;
    for(int i=1;i<s.size();i++)
    {
        int k=0;
        while((sa[i]+k<s.size()) && (sa[i-1]+k<s.size()) && s[sa[i]+k]==s[sa[i-1]+k])k++;
        lcp[i]=k;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>s;
        build();
        compute();
        int res=0;
        for(int i=0;i<s.size();i++)
        {
            res = res + s.size() - sa[i]-lcp[i];
        }
        printf("%d\n",res);
    }
    return 0;
}
