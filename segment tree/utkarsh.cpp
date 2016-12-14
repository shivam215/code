/*
-----------------------------------------------------------------------------
Author :            ---------------------------------------------------------
    UTKAR$H $AXENA  ---------------------------------------------------------
    IIT INDORE      ---------------------------------------------------------
-----------------------------------------------------------------------------
*/
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define fre 	freopen("0.in","r",stdin),freopen("0.out","w",stdout)
#define abs(x) ((x)>0?(x):-(x))
#define MOD 1000000007
#define lld signed long long int
#define pii pair<int,int>

#define print(x) printf("%d\n",x)

#define printll(x) printf("%lld\n",x)
vector<int> G[2*100000+5];
lld P[1000000+4];
int give(string x){
	lld ans = 0;
	for(int i=0;i<x.size();++i){
		ans = ans*10 + (x[i]-'0');
		ans %= MOD;
	}
		return ans;
}
struct st{
	int len = 0;
	lld ans = 0;
}tree[100000*4+5];
void update(int i,int si,int sj,int q,int L,lld pp){
	if(si==sj){
		tree[i].len = L;
		tree[i].ans = pp % MOD;
	}
	else{
		int mid = (si+sj)/2;
		if(q<=mid)
			update(2*i,si,mid,q,L,pp);
		else
			update(2*i+1,mid+1,sj,q,L,pp);
		tree[i].len = tree[2*i].len + tree[2*i+1].len;
		lld x = tree[2*i].ans * P[ tree[2*i+1].len];
		tree[i].ans = (x  + tree[2*i+1].ans) % MOD;
	}
}
st query(int i,int si,int sj,int qi,int qj){
	if(si==qi and sj==qj)
		return tree[i];
	int mid = (si+sj)/2;
	if(qj<=mid)
		return query(2*i,si,mid,qi,qj);
	else if(mid+1<=qi)
		return query(2*i+1,mid+1,sj,qi,qj);
	st a =  query(2*i,si,mid,qi,mid);
	st b = query(2*i+1,mid+1,sj,mid+1,qj);
	st c;
	c.len = a.len+b.len;
	c.ans = (a.ans * P[b.len] + b.ans) % MOD;
	return c;
}
int main(){
	//fre;
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	P[0] = 1;
	for(int i=1;i<=1000000;++i){
		P[i] = (P[i-1]*10) % MOD;
	}
	int N;
	cin>>N;
	string x;
	for(int i=1;i<=N;++i){
		cin>>x;
		update(1,1,N,i,x.length(),give(x));
	}
	int i,c,Q,L,R;
	cin>>Q;
	while(Q--){
			cin>>c;
		if(c==0){
			cin>>L>>R;
			printll(query(1,1,N,L,R).ans);
		}
		else{
				cin>>i;
			cin>>x;
			update(1,1,N,i,x.length(),give(x));
		}
	}
}
