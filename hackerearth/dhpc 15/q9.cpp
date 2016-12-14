#include <bits/stdc++.h>
#define inf 1000000000
#define mod 1000000007
#define scano(x) scanf("%d",&x)
#define scanll(x) scanf("%lld",&x)
#define scant(x,y) scanf("%d%d",&x,&y)
#define pb push_back
#define mp make_pair
#define ll long long int
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fe first
#define se second
#define MAX 1000000
using namespace std;
int prime[MAX],dis[MAX];
void sieve()
{
    for(int i=2;i<MAX;i++)prime[i]=1;
    for(ll i=2;i<MAX;i++)
    {
        if(prime[i])
        {
        for(ll j=i*i;j<MAX;j+=i)
        {
            prime[j]=0;
        }
        }
    }
}
void bfs(int a,int b)
{
    for(int i=1;i<MAX;i++)dis[i]=-1;
    queue<int> q;
    while(!q.empty())q.pop();
    q.push(a);
    dis[a]=0;
    while(!q.empty())
    {
        int c = q.front();
        q.pop();
        if(c==b)break;
        for(int i=0;i<20;i++)
        {
            int temp = (c^(1<<i));
            if(temp>=MAX)continue;
            if(prime[temp])
            {
                if(dis[temp]==-1)
                {
                    dis[temp] = dis[c]+1;
                    q.push(temp);
                }
            }
        }
    }
}
int main()
{
    int t;
    scano(t);
    sieve();
    while(t--)
    {
        int a,b;
        scant(a,b);
        if(prime[a]==0||prime[b]==0)
        {
            printf("Impossible\n");
            continue;
        }
        bfs(a,b);
        if(dis[b]==-1)printf("Impossible\n");
        else printf("%d\n",dis[b]);
    }
    return 0;
}
