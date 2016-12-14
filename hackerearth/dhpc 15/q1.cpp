#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define abs(x) ((x)>0?(x):-(x))
#define MOD 1000000007
#define lld signed long long int
#define pii pair<int,int>
#define scan(x) scanf("%d",&x)
#define print(x) printf("%d\n",x)
#define scanll(x) scanf("%lld",&x)
#define printll(x) printf("%lld\n",x);
#define MAX 10000007
lld a[MAX];
map<lld,bool> fdp;
map<lld,lld>dp;
lld rec(lld N){
	if(N==0)return 0;
    if(N<MAX)
    {
        if(a[N]!=-1)return a[N];
    }
	else if(fdp[N])return dp[N];
	lld res = rec(N/2)+rec(N/3) + rec(N/4)+rec(N/5)+rec(N/6);
	if(res<N)res=N;
	if(N<MAX)a[N]=res;
	else
    {
        fdp[N]=1;
        dp[N]=res;
    }
    return res;
}
int main(){
	int T;
	scan(T);
	for(int i=0;i<MAX;i++)a[i]=-1;
	lld N;
	while(T--){
		scanll(N);
		lld res = rec(N);
		res%=MOD;
		printf("%lld\n",res);
	}
	return 0;
}
