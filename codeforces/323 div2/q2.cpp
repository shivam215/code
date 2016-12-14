#include <bits/stdc++.h>
#define inf 1000000000
#define mod 1000000007
#define scano(x) scanf("%d",&x)
#define scanll(x) scanf("%lld",&x)
#define scant(x,y) scanf("%d%d",&x,&y)
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fe first
#define se second
using namespace std;
int a[1003],vis[1003];
int main()
{
    int n;
    cin>>n;
    rep(i,0,n)cin>>a[i];
    int dir=0,ans=0,cur=0;
    while(1)
    {
        int flag=0;
        if(dir==0)
        {
            rep(i,0,n)
            {
                if(!vis[i]&&cur>=a[i])
                {
                    vis[i]=1;
                    cur++;
                    flag=1;
                }
            }
        }
        else
        {
            for(int i=n-1;i>=0;i--)
            {
                if(!vis[i]&&cur>=a[i])
                {
                    vis[i]=1;
                    cur++;
                    flag=1;
                }
            }
        }
        dir = 1-dir;
        if(flag==0)break;
        ans++;
    }
    cout<<ans-1<<endl;
    return 0;
}
