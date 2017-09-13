//https://www.codechef.com/MAY17/problems/GPD/

#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;
const int B = 32;

int root[N], L[N * B], R[N * B];
vector < int > V[N];
int A[N];
unordered_map < int, int > M;
int node = 0;

int update(int bpos, int id, int val) {
	int ID = ++node;
	if(bpos < 0) {
		return ID;
	}

	L[ID] = L[id];
	R[ID] = R[id];

	if(val & (1 << bpos)) {
		R[ID] = update(bpos - 1, R[id], val);
	}
	else {
		L[ID] = update(bpos - 1, L[id], val);
	}

	return ID;
}

int Mquery(int bpos, int id, int k) {
	if(bpos < 0) {
		return 0;
	}
	if(k & (1 << bpos)) {
		if(L[id]) {
			return (1 << bpos) | Mquery(bpos - 1, L[id], k);
		}
		else {
			return Mquery(bpos - 1, R[id], k);
		}
	}
	else {
		if(R[id]) {
			return (1 << bpos) | Mquery(bpos - 1, R[id], k);
		}
		else {
			return Mquery(bpos - 1, L[id], k);
		}
	}
}

int mquery(int bpos, int id, int k) {
	if(bpos < 0) {
		return 0;
	}

	if(k & (1 << bpos)) {
		if(R[id]) {
			return mquery(bpos - 1, R[id], k);
		}
		else {
			return (1 << bpos) | mquery(bpos - 1, L[id], k);
		}
	}
	else {
		if(L[id]) {
			return mquery(bpos - 1, L[id], k);
		}
		else {
			return (1 << bpos) | mquery(bpos - 1, R[id], k);
		}
	}
}

void dfs(int u, int p) {
	root[u] = update(31, root[p], A[u]);
	for(int v : V[u]) {
		if(v == p) {
			continue;
		}
		dfs(v, u);
	}
}

int main() {
	int n, q;
	scanf("%d %d", &n, &q);
	int r, key;
	scanf("%d %d", &r, &key);
	int done = 0;
	M[r] = ++done;
	A[done] = key;
	for(int i = 1; i < n; ++i) {
		int v, u, k;
		scanf("%d %d %d", &u, &v, &k);
		if(!M.count(v)) {
			M[v] = ++done;
		}
		if(!M.count(u)) {
			M[u] = ++done;
		}
		v = M[v];
		u = M[u];
		V[v].push_back(u);
		V[u].push_back(v);
		A[u] = k;
	}
	dfs(1, 0);

	int last = 0;
	while(q--) {
		int type;
		scanf("%d", &type);

		type ^= last;

		if(type == 0) {
			int v, u, k;
			scanf("%d %d %d", &v, &u, &k);
			v ^= last;
			u ^= last;
			k ^= last;

			assert(!M.count(u));
			M[u] = ++done;
			A[done] = k;

			root[done] = update(31, root[M[v]], k);
		}
		else {
			int v, k;
			scanf("%d %d", &v, &k);
			v ^= last;
			k ^= last;

			v = M[v];

			int mn = mquery(31, root[v], k);
			int mx = Mquery(31, root[v], k);

			last = mn ^ mx;
			printf("%d %d\n", mn, mx);
		}
	}
}
