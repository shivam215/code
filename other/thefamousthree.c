#include <stdio.h>
int power(int x, int y);
int main()
{
    int T,i,N,j,r;
    unsigned int s,b,g,count;
     scanf("%d",&T);
    for(i=1;i<=T;i++)
    {   s=1;b=2;g=6;count=9;
        scanf("%d",&N);
        for(j=2;j<=N;j++)
        {  r = power(10,9)+7;
           s = ((2*b) + (2*g))%r;
           b = ((2*g) + (2*s))%r;
           g = ((2*s) + (2*b))%r;
           if(j==9)
           {
               printf("%u\t%u\t%u\n",s,b,g);
           }
           count = (s+b+g)%r;
        }
        printf("%u\n",count);
        }
        return 0;
}
int power(int x, int y)
{ int i,result=1;
for(i=1;i<=y;i++)
{ result = result*x;}
return result;
}





























































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































