#include <bits/stdc++.h>
#define mod 1000000000LL
#define ll long long
using namespace std;
ll pre[2003],cum[2003];
ll countFact(int n, int p)
{
    int k=0;
    while (n>0)
    {
        k+=n/p;
        n/=p;
    }
    return k;
}
ll pow(int a, int b, ll MOD)
{
	ll x=1,y=a;
	while(b > 0)
	{
		if(b&1)
		{
			x=(x*y);
			if(x>=MOD) x%=MOD;
		}
		y = (y*y);
		if(y>=MOD) y%=MOD;
		b /= 2;
	}
	return x;
}

ll C(int n, int r, ll MOD)
{
	ll res = 1;
	vector<bool> isPrime(n+1,1);
	for (int i=2; i<=n; i++)
		if (isPrime[i])
		{
			for (int j=2*i; j<=n; j+=i)
				isPrime[j]=0;
			int k = countFact(n,i) - countFact(r,i) - countFact(n-r,i);
			res = (res * pow(i, k, MOD));
			if(res>=MOD)res%=MOD;
		}
	return res;
}
int main()
{
  ios_base::sync_with_stdio(false);
  int t,n,m,i,j;
  ll res;
  cin>>t;
  while(t--)
  {
    cin>>n>>m;
    pre[0] = 1;
    cum[0] = 1;
    for(i=1;i<=m;i++)
    {
      pre[i] = C(m+i-1,i,mod);
      cum[i] = (cum[i-1] + pre[i]);
      if(cum[i]>=mod)cum[i]%=mod;
      //cout<<cum[i]<<endl;
    }
    for(i=2;i<=n;i++)
    {
      for(j=1;j<=m;j++)
      {
        ll temp = (cum[j]*pre[j]);
        if(temp>=mod)temp%=mod;
        cum[j] = (cum[j-1] + temp);
        if(cum[j]>=mod)cum[j]%=mod;
      }
    }
    printf("%lld\n",cum[m]);
  }
  return 0;
}
