#include <bits/stdc++.h>
#define ll long long

using namespace std;
ll fastexp(int a,int b)
{
    ll res=1;
    while(b>0)
    {
        if(b&1)res=(res*a);
        a=(a*a);
        b>>=1;
    }
    return res;
}

long long a[200010];
long long left_or[200010];
long long right_or[200010];
long long OR[200010];

int n,x,k;

int main()
{
	cin >> n >> k >> x;
	long long mul;
	for(int i = 0;i < n;i++)
		cin >> a[i];

	left_or[0] = 0;
	for(int i = 1;i < n;i++)
	{
		left_or[i] = a[i-1] | left_or[i-1];
	}

	right_or[n-1] = 0;
	for(int i = n-2;i >= 0;i--)
	{
		right_or[i] = a[i+1] | right_or[i +1];
	}
	mul = fastexp(x,k);
	for(int i = 0;i < n;i++)
	{
		OR[i] = left_or[i] | right_or[i] | (a[i] * mul);
	}

	long long ans;
	ans = *(max_element(OR,OR+n));
	cout << ans << endl;
}
