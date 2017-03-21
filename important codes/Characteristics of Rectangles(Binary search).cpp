//http://codeforces.com/contest/333/problem/D

//Binary search + hashing

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <sstream>
#include <stack>
#include <cassert>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back
#define sz(x) ((x).size())
#define mp make_pair
#define x first
#define y second

const int N = 1010;
const int M = 2000010;
const int inf = 0x3f3f3f3f;
const double eps = 1e-6;

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <set>

using namespace std;

int n, m, a[N][N], b[N][N], c[N][N];

bool check(int x){
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			b[i][j] = a[i][j] >= x;
	memset(c, 0, sizeof(c));
	vector<int> vt[N];
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++)
			if(b[j][i]) vt[i].pb(j);
	}


	for(int i = 1; i <= m; i++){
		for(int j = 0; j < vt[i].size(); j++){
			for(int k = j + 1; k < vt[i].size(); k++){
				int A = vt[i][j];
				int B = vt[i][k];
				if(c[A][B]) return 1;
				c[A][B] = 1;
			}
		}
	}
	return 0;
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);
	int l = 0, r = inf, ret = 0;
	while(l <= r){
		int mid = (l + r) >> 1;
		if(check(mid)) l = mid + 1, ret = mid;
		else r = mid - 1;
	}
	cout << ret << endl;
	return 0;
}
