#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef pair<int,int> ii;
typedef pair< int,pair<int,int> > iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
int n,m,a,b;
int arr[102][102],spt[102][102],dp[102][102];
priority_queue<iii,vector<iii>,greater<iii> > Q;
void dijkstra()
{
    memset(spt,false,sizeof(spt));
    int first[4] = {1,-1,0,0};
    int second[4] = {0,0,1,-1};
    //spt[src]=true;
	while(!Q.empty())
	{
		iii tp=Q.top();
		int x = tp.second.first;
		int y = tp.second.second;
		int z = tp.first;
		Q.pop();
		//cout<<v<<endl;
		if(x==a && y==b)break;
		spt[x][y]=true;
		for(int i=0;i<4;i++)
        {
        if(x+first[i]>=0 && x+first[i]<n && y+second[i]>=0 && y+second[i]<m)
        {
            int f = x+first[i];
            int g = y+second[i];
            if(!spt[f][g]&&dp[f][g]>dp[x][y]+arr[f][g])
            {
                dp[f][g] = dp[x][y] + arr[f][g];
                Q.push(mp(dp[f][g],mp(f,g)));
            }
        }
        }
    }
}
int main()
{
    int t,time;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=0;i<n;i++)for(int j=0;j<m;j++){cin>>arr[i][j];dp[i][j]=INT_MAX;}
        cin>>a>>b>>time;
        a--;b--;
        dp[0][0] = arr[0][0];
        while(!Q.empty())Q.pop();
        Q.push(mp(dp[0][0],mp(0,0)));
        dijkstra();
        int diff = time-dp[a][b];
        if(diff>=0){cout<<"YES"<<endl;cout<<diff<<endl;}
        else cout<<"NO"<<endl;
    }
    return 0;
}
