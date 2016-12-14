#include <bits/stdc++.h>
#define MAX 100005
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
void dfs(int root)
{

}
int main()
{
    while(1)
    {
        int n;
        cin>>n;
        if(n==0)break;
        rep(i,1,n+1)
        {
            int a;
            string s;
            cin>>a>>s;
            if(s=="false")
            {
                st[i] = mp(a,0);
            }
            else st[i]=mp(a,1);
        }
        memset(mark,-1,sizeof(mark));
        rep(i,1,n+1)
        {
            if(mark[i]==-1)
            {
                dfs(i);
            }
        }


    }
}
