#include <stdio.h>
int power(int x, int y);
void exponent(unsigned long long int M[3][3], int n);
void multiply(unsigned long long int M[3][3], unsigned long long  int N[3][3]);
int main()
{
    int T,i,n;
    unsigned int  a[3] = {1,2,6};
    unsigned int result,r;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {   unsigned long long int M[3][3] = {{0,2,2},{0,4,6},{0,12,16}};
        unsigned int b[3];
        scanf("%d",&n);
        if(n==1){printf("9\n"); continue;}
        exponent(M,n-1);
        r = power(10,9)+7;
        //printf("%llu\t%llu\t%llu\n%llu\t%llu\t%llu\n%llu\t%llu\t%llu\t",M[0][0],M[0][1],M[0][2],M[1][0],M[1][1],M[1][2],M[2][0],M[2][1],M[2][2]);
        b[0] = (M[0][1]*a[1] + M[0][2]*a[2])%r;
        b[1] = (M[1][1]*a[1] + M[1][2]*a[2])%r;
        b[2] = (M[2][1]*a[1] + M[2][2]*a[2])%r;
        //printf("%u\t%u\t%u\n",b[0],b[1],b[2]);

        result = (b[0]+b[1]+b[2])%r;
        printf("%u\n",result);
    }
}
int power(int x, int y)
{ int result=1;
int i;
for(i=1;i<=y;i++)
{ result = result*x;}
return result;
}
void exponent(unsigned long long int M[3][3], int n)
{
    if(n==0 || n==1)
        return;
    unsigned long long int F[3][3] = {{0,2,2},{0,4,6},{0,12,16}};
    exponent(M,n/2);
    multiply(M,M);
    if(n%2 != 0)
        multiply(M,F);

}
void multiply(unsigned long long int M[3][3], unsigned long long int N[3][3])
{   unsigned int r = power(10,9)+7;
    unsigned long long int a = (((M[0][0]*N[0][0])) + ((M[0][1]*N[1][0])) + ((M[0][2]*N[2][0])))%r;
    unsigned long long int b = (((M[0][0]*N[0][1])) + ((M[0][1]*N[1][1])) + ((M[0][2]*N[2][1])))%r;
    unsigned long long int c = (((M[0][0]*N[0][2])) + ((M[0][1]*N[1][2])) + ((M[0][2]*N[2][2])))%r;
    unsigned long long int d = (((M[1][0]*N[0][0])) + ((M[1][1]*N[1][0])) + ((M[1][2]*N[2][0])))%r;
    unsigned long long int e = (((M[1][0]*N[0][1])) + ((M[1][1]*N[1][1])) + ((M[1][2]*N[2][1])))%r;
    unsigned long long int f = (((M[1][0]*N[0][2])) + ((M[1][1]*N[1][2])) + ((M[1][2]*N[2][2])))%r;
    unsigned long long int g = (((M[2][0]*N[0][0])) + ((M[2][1]*N[1][0])) + ((M[2][2]*N[2][0])))%r;
    unsigned long long int h = (((M[2][0]*N[0][1])) + ((M[2][1]*N[1][1])) + ((M[2][2]*N[2][1])))%r;
    unsigned long long int i = (((M[2][0]*N[0][2])) + ((M[2][1]*N[1][2])) + ((M[2][2]*N[2][2])))%r;
    M[0][0] = a;
    M[0][1] = b;
    M[0][2] = c;
    M[1][0] = d;
    M[1][1] = e;
    M[1][2] = f;
    M[2][0] = g;
    M[2][1] = h;
    M[2][2] = i;


}
