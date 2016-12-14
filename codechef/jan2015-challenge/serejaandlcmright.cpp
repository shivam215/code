#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define LL long long

vector<int> factorize(int n)
{
	vector<int> vec;
	for(int i=2;i*i<=n;++i)
	{
		if(n%i==0)
		{
			int cnt = 1;
			while(n%i==0)
			{
				cnt *= i;
				n /= i;
			}
			vec.push_back(cnt);
		}
	}
	if(n!=1)
		vec.push_back(n);
	return vec;
}

LL power(LL a,LL b)
{
	LL res = 1;
	while(b)
	{
		if(b&1)
			res *= a;
		a *= a;
		a %= MOD;
		res %= MOD;
		b >>= 1;
	}
	return res%MOD;
}

int solve(int m,int n,int d)
{
	long long ans = 0;
	int x;
	ans += power(m,n);
	vector<int> fact = factorize(d);
	cout << ans << " " << fact.size() << endl;
	for(int i=0;i<fact.size();++i)
		cout << fact[i] << " ";
	cout << endl;
	if(fact.size())
	{
		int sz = fact.size();
		cout << "Debug : " << sz << endl;
		for(int i=1;i<(1<<sz);++i)
		{
			vector<int> subset;
			for(int j=0;j<sz;++j)
				if((1<<j)&i)
					subset.push_back(fact[j]);
			cout << "Subset Corresponding to " << i << endl;
			for(int i=0;i<subset.size();++i)
				cout << subset[i] << " ";
			cout << endl;
			x = m;
			for(int j=1;j<(1<<subset.size());++j)
			{
				int cnt = 1;
				for(int k=0;k<subset.size();++k)
					if((1<<k)&j)
						cnt *= subset[k];
				if(__builtin_popcount(j)%2==1)
					x -= m/cnt;
				else
					x += m/cnt;
			}
			cout<<"x is"<<x<<endl;
			if(__builtin_popcount(i)%2==1)
				ans -= power(x,n);
			else
				ans += power(x,n);
            cout<<"ans"<<ans<<endl;
			while(ans<0)
				ans += MOD;
			ans %= MOD;
		}
	}
	return ans%MOD;
}

int main()
{
	int t,n,m,l,r;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d",&n,&m,&l,&r);
		long long ans = 0;
		for(int d=l;d<=r;++d)
		{
			ans += solve(m,n,d);
			ans %= MOD;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
