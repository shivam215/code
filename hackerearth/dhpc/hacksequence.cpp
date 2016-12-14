#include <iostream>
#define r 1000000007
void power(long long M[2][2], long long m);
void multiply(long long M[2][2],long long F[2][2]);
using namespace std;
int main()
{
    int i,j;
    long long n,result,t;
    cin>>t;
    for(i=1;i<=t;i++)
    {   long long M[2][2] = {{2014,69},{1,0}};
        cin>>n;
        if(n==1||n==2)
            result = 1;
        else
        {
            power(M,n-2);
            result = ((M[0][0])%r+ (M[0][1])%r)%r;
        }
        cout<<result<<endl;

    }
    return(0);
}
void power(long long M[2][2], long long m)
{
    if(m==0 || m==1)
        return;
    long long  F[2][2] = {2014,69,1,0};
    power(M,m/2);
    multiply(M,M);
    if(m%2 != 0){multiply(M,F);}
}
void multiply(long long M[2][2], long long F[2][2])
{
    long long a = (M[0][0]*F[0][0])%r;
    long long b = (M[0][1]*F[1][0])%r;
    a = (a+b)%r;
    long long c = (M[0][0]*F[0][1])%r;
    long long d = (M[0][1]*F[1][1])%r;
    c = (c+d)%r;
    long long e = (M[1][0]*F[0][0])%r;
    long long f = (M[1][1]*F[1][0])%r;
    e = (e+f)%r;
    long long g = (M[1][0]*F[0][1])%r;
    long long h = (M[1][1]*F[1][1])%r;
    g = (g+h)%r;

    M[0][0] = a;
    M[0][1] = c;
    M[1][0] = e;
    M[1][1] = g;

}

