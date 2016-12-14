#include <bits/stdc++.h>
using namespace std;
long long krish(long long x)
{
    long long s=0;
    while(x)
    {
        s = s + x%10;
        x = x/10;
    }
    if(s>9)s=krish(s);
    return s;
}
long long gcd(long long a, long long b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
int main()
{
    int t;
    long long a,b,c,p,i;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c>>p;
        long long x=a%9,ans=1;
        while(b>0){
            if(b%2==1) ans=(ans*x)%9;
                ans=(ans*ans)%9;
            b/=2;
        }
        p += krish(ans);
        long long k,m;
        ans = p/c;
        for(i=2*c;i<=p;i+=c)
        {
            k =0;
            for(m=i+c;m<=p;m+=c)
            {
                if(gcd(i,m)==c)k++;
            }
            ans+=k;
        }
          printf("%d\n",ans);
    }
    return 0;
}

