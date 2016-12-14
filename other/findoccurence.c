#include <stdio.h>
inline void fastWrite(int a)
{
char c;
char snum[20];
int i=0;
do
{
snum[i++]=a%10+48;
a=a/10;
}while(a!=0);
i=i-1;
while(i>=0)
putchar(snum[i--]);
putchar('\n');
}
inline void fastRead(int *a)
{
char c=0;
while (c<33) c=getchar();
*a=0;
while (c>33)
{
*a=*a*10+c-'0';
c=getchar();
}
}
int findoccurence(int *a, int number);
int main()
{
    int N,Q,number,result;
    fastRead(&N);
    int a[N],i;
    for(i=0;i<N;i++)
    {
        fastRead(&a[i]);
    }
    fastRead(&Q);
    for(i=1;i<=Q;i++)
    {   fastRead(&number);
        result = findoccurence(a,number);
        fastWrite(result);
    }
    return(0);

}
int findoccurence(int *a, int number)
{
    int j,count=0;
    for(j=0;a[j];j++)
    {
       if(a[j]==number)
            count++;
    }
    return count;

}
