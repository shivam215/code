#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[25],avg;
int n,k;
bool solve()
{
    ll inc = 0;
    int freq=0;
    int x = (1<<n)-1;
    for(int i=0;i<=x;i++)
    {
        if(i&inc)continue;
        ll sum = 0;
        for(int j=0;j<n;j++)
        {
            if(i&(1<<j))
            {
                sum = sum + a[j];
            }
        }
        if(sum==avg)
        {
            freq++;
            inc = inc|i;
        }
    }
    if(freq==k)return true;
    return false;
}
int main()
{
    int t,flag;
    cin>>t;
    while(t--)
    {
        avg=0;
        flag=1;
        cin>>n>>k;
        for(int i=0;i<n;i++){cin>>a[i];avg+=a[i];}
        if(avg==0&&k<=n)
		{printf("yes\n");
		continue;}
		if(k>n) flag=0;
		if(avg%k==0)
			avg/=k;
		else
			flag=0;
		for(int i=0;i<n;i++)
		{
			if(a[i]>avg)
				flag=0;
		}
        if(flag)
        {
        if(solve())cout<<"yes"<<endl;
        else cout<<"no"<<endl;
        }
        else cout<<"no"<<endl;
    }
    return 0;

}
