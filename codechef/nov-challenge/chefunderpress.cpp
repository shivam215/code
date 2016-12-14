#include<bits/stdc++.h>
#define INF 10009
#define K 109
#define pb push_back
using namespace std;

int n,k,q,b;

int *p;
int *F;
bool vp[K];

void dfs(int s, vector<vector<int> >& g, vector<vector<unsigned int> >& dp, vector<vector<unsigned int> >& soln) {

	int u,v,i,j;
	dp[s][F[s]] = s; //base value as self..
	soln[s][F[s]] = s;
	for(i=0; i<g[s].size(); i++) {
		u = s;
		v = g[s][i];
		if(p[v] != -1)
			continue;
		p[v] = u;
		dfs(v,g,dp,soln);
		for(j=1; j<=k; j++) {
			dp[u][j] = min(dp[u][j], dp[v][j]);
			soln[u][j] = dp[u][j];
		}
	}
}

int main() {
	int i,j,u,x,y;
	scanf("%d%d",&n,&k);
	scanf("%d",&b);
	vector<vector<int> > g(n+1);
	vector<vector<unsigned int> > dp(n+1);
	vector<vector<unsigned int> > soln(n+1);

	for(i=0; i<=n; i++) {
		dp[i].resize(k+1,-1);
		soln[i].resize(k+1,-1);
	}
	/*for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            printf("%u\n",dp[i][j]);
        }
    }*/
	p = (int *)malloc((n+1) * sizeof(int));
	F = (int *)malloc((n+1) * sizeof(int));

	memset(p,-1,sizeof(int)*(n+1));

	for(i=0; i<n-1; i++) {
		scanf("%d%d",&x,&y);
		g[x].pb(y);
		g[y].pb(x);
	}
	for(i=1; i<=n; i++) {
		scanf("%d",&F[i]);
		vp[F[i]] = 1;
	}
	p[b] = b;
	dfs(b,g,dp,soln);
	scanf("%d",&q);
	while(q--) {
		scanf("%d%d",&u,&y);
		if(!vp[y]) {
		    printf("-1\n");
			continue;
		}
		while(soln[u][y]>=INF && p[u]!=u)
        {
            u = p[u];
        }
        printf("%u\n",soln[u][y]);


		/*x = u;
		while(soln[x][y] >= INF && p[x] != x) x = p[x];
		while(soln[u][y] >= INF && p[u] != u) {
			soln[u][y] = soln[x][y];
		    u = p[u];
		}
		printf("%u\n",soln[x][y]);*/
	}
}
