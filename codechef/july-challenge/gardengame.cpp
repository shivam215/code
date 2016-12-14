#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
long long gcd(long long a, long long b)
{
    if(b==0)
        return a;
    else
        return(gcd(b,a%b));
}
long long mod_of_lcm(vector<long long> a)
{
	long long ans=1;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]!=1)
		{
			for(long long j=i+1;j<a.size();j++)
                a[j]/=gcd(a[i],a[j]);
			ans=(ans*a[i])%mod;
		}
	}
	return ans;
}
/*long long lcm(long long a, long long b)
{
    long long temp = a*b;
    return((temp/gcd(a,b))%mod);

}*/
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t;
    long long n,x,i,j,cnt,res;
    vector<long long> v;
    cin>>t;
    while(t--)
    {
        v.clear();
        cin>>n;
        long long a[n+1];
        long long b[n+1];
        for(i=0;i<n+1;i++)
            b[i]=0;
        for(i=1;i<=n;i++)
        {
            cin>>x;
            a[i] = x;
        }
        for(i=1;i<=n;i++)
        {
            if(b[i]==0)
            {
                if(a[i]==i)
                {
                    b[i]=1;
                    continue;
                }
                else
                {
                    j=i;
                    b[j]=1;
                    cnt=1;
                    while(a[j]!=i)
                    {
                        j = a[j];
                        b[j]=1;
                        cnt++;
                    }
                    v.push_back(cnt);
                }

            }
        }
        //for(i=0;i<v.size();i++)
            //cout<<v[i]<<endl;
        /*if(v.size()==0)
            {cout<<"1"<<endl;
            continue;}
        res = v[0];
        for(i=1;i<v.size();i++)
        {
            res = lcm(res,v[i]);
        }
        cout<<res<<endl;*/
        cout<<mod_of_lcm(v)<<endl;;
    }
    return(0);

}
