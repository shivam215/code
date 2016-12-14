#include <bits/stdc++.h>
#define scano(x) scanf("%d",&x)
#define scant(x,y) scanf("%d%d",&x,&y)
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int a[102];
string g[102];
int main()
{
    int n;
    vector<int> v;
    scano(n);
    rep(i,0,n)cin>>g[i];
    rep(i,0,n)scano(a[i]);
    int ok=1;
    while(true)
    {
        int i;
        for(i=0;i<n;i++)
        {
            if(a[i]==0)break;
        }
        if(i==n)break;
        rep(j,0,n)
        {
            if(g[i][j]=='1')
            {
                a[j]--;
            }
        }
        v.push_back(i);
    }
    cout<<v.size()<<endl;
    rep(i,0,v.size())cout<<v[i]+1<<' ';
    cout<<endl;
    return 0;

}
