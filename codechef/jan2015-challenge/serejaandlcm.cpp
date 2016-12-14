#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
long long fastexpmod(long long a, long long b)
{
    long long x = 1;
    long long y=a;
    while(b>0)
    {
        if(b&1)
        {
            x = (x*y)%mod;
        }
        y = (y*y)%mod;
        b>>=1;
    }
    return(x%mod);
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t;
    long long n,m,l,r,res,j,sum,k;
    vector <long long> v;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>l>>r;
        res=0;
        for(long long i=l;i<=r;i++)
        {
            v.clear();
            long long m1 = i;
            k=2;
            while(k<=m1)
        {
           if(m1%k==0)
           {   sum=1;
               while(m1%k==0)
               {
                   sum = sum*k;
                   m1 = m1/k;
               }
               v.push_back(sum);
           }
           k++;
        }
        //for(int j=0;j<v.size();j++)
            //cout<<v[j]<<endl;
        int siz = v.size();
        if(siz==1 || i==1)
            res = (res + fastexpmod(m,n) - fastexpmod(m-m/i,n))%mod;
        else if(siz==2)
        {
            res = (res + fastexpmod(m,n)-fastexpmod(m-m/v[0],n)-fastexpmod(m-m/v[1],n)+fastexpmod(m-m/v[0]-m/v[1]+m/(v[0]*v[1]),n))%mod;
        }
        else if(siz==3)
        {
            res = (res + fastexpmod(m,n)-fastexpmod(m-m/v[0],n)-fastexpmod(m-m/v[1],n)-fastexpmod(m-m/v[2],n)+fastexpmod(m-m/v[0]-m/v[1]+m/(v[0]*v[1]),n)+fastexpmod(m-m/v[1]-m/v[2]+m/(v[1]*v[2]),n)+fastexpmod(m-m/v[0]-m/v[2]+m/(v[0]*v[2]),n)-fastexpmod(m-m/v[0]-m/v[1]-m/v[2]+m/(v[0]*v[1])+m/(v[1]*v[2])+m/(v[0]*v[2])-m/(v[0]*v[1]*v[2]),n))%mod;
        }
        else if(siz==4)
        {
            res = (res + fastexpmod(m,n)-fastexpmod(m-m/v[0],n)-fastexpmod(m-m/v[1],n)-fastexpmod(m-m/v[2],n)-fastexpmod(m-m/v[3],n)+fastexpmod(m-m/v[0]-m/v[1]+m/(v[0]*v[1]),n)+fastexpmod(m-m/v[1]-m/v[2]+m/(v[1]*v[2]),n)+fastexpmod(m-m/v[0]-m/v[2]+m/(v[0]*v[2]),n)+fastexpmod(m-m/v[0]-m/v[3]+m/(v[0]*v[3]),n)+fastexpmod(m-m/v[1]-m/v[3]+m/(v[1]*v[3]),n)+fastexpmod(m-m/v[2]-m/v[3]+m/(v[2]*v[3]),n)-fastexpmod(m-m/v[0]-m/v[1]-m/v[2]+m/(v[0]*v[1])+m/(v[1]*v[2])+m/(v[0]*v[2])-m/(v[0]*v[1]*v[2]),n)-fastexpmod(m-m/v[0]-m/v[1]-m/v[3]+m/(v[0]*v[1])+m/(v[1]*v[3])+m/(v[0]*v[3])-m/(v[0]*v[1]*v[3]),n)-fastexpmod(m-m/v[3]-m/v[1]-m/v[2]+m/(v[3]*v[1])+m/(v[1]*v[2])+m/(v[3]*v[2])-m/(v[3]*v[1]*v[2]),n)+fastexpmod(m-m/v[0]-m/v[1]-m/v[2]-m/v[3]+m/(v[0]*v[1])+m/(v[1]*v[2])+m/(v[0]*v[2])+m/(v[0]*v[3])+m/(v[1]*v[3])+m/(v[2]*v[3])-m/(v[0]*v[1]*v[2])-m/(v[0]*v[1]*v[3])-,n))%mod;
        }

        }
        cout<<res<<endl;
    }
    return(0);
}
