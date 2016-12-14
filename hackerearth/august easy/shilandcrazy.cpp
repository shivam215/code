#include<bits/stdc++.h>
#define ll long long
#define loop(i,a,b) for(int i=a;i<b;i++)
using namespace std;
ll mod= 1000000007;
int a[100001];
int p[100001];
int vis[100001];
vector<int> v[100001];
vector<int> pos[100001];
int main()
{
    int n;
    cin>>n;
    ll t;
    cin>>t;
    for(int i=1;i<=n;i++)
    cin>>a[i];

    loop(i,1,n+1)
    cin>>p[i];
    int comp=0;
    loop(i,1,n+1)
    {
        if(vis[i]==0)
        {

            int j=i;
            int source=i;
            comp++;
            while(p[j]!=source)
            {
                vis[j]=1;
                v[comp].push_back(a[j]);
                pos[comp].push_back(j);
                j=p[j];
            }
            vis[j]=1;
            v[comp].push_back(a[j]);
            pos[comp].push_back(j);

        }
    }
    vector<int> ta;
    loop(i,1,comp+1)
    {
        ta.clear();

        loop(j,0,v[i].size())
        ta.push_back(v[i][j]);


        loop(j,0,v[i].size())
        ta.push_back(v[i][j]);

        ll r=t%(ll)v[i].size();
        loop(j,0,v[i].size())
        a[pos[i][j]-1]=ta[r+j];
    }

    loop(i,1,n+1)
    printf("%d ",a[i-1]);


    cout<<"\n";

    return 0;
}
