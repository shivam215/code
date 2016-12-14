#include <bits/stdc++.h>
#define scanint(x) scanf("%d",&x)
#define scanll(x) scanf("%lld",&x)
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
vector< pii > e;
bool comp(pii a, pii b)
{
    return (a.second-a.first)>(b.second-b.first);
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        int n,k;
        cin>>n>>k;
        s.resize(n);
        e.clear();
        for(int i=0;i<k;i++)
        {
            int a,b;
            cin>>a>>b;
            e.push_back(mp(a,b));
        }
        sort(e.begin(),e.end(),comp);
        for(int i=0;i<e.size();i++)cout<<e[i].first<<' '<<e[i].second<<endl;
        for(int i=0;i<e.size();i++)
        {
            int a = e[i].first;
            int b = e[i].second;
            for(int i=a;i<a+((b-a+1)/2);i++)
            {
                s[i] = '(';
            }
            for(int i=a+(b-a+1)/2;i<=b;i++)
            {
                s[i] = ')';
            }
        }
        for(int i=0;i<n;i++)
        {
            if(s[i]!='('&&s[i]!=')')
            {
                s[i]='(';
            }
        }
        cout<<s<<endl;
    }
    return 0;
}
