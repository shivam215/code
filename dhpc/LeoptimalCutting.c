#include <stdio.h>
#include <limits.h>
int findmin(int n, int m);
int min(int n, int m);
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b =t;
}
int main()
{
    int T,n,m,result,j;
    scanf("%d",&T);
    for(j=1;j<=T;j++)
    {
    scanf("%d",&n);
    scanf("%d",&m);
    result = findmin(n,m);
    printf("%d\n",result);
    }
    return(0);
}
int findmin(int n, int m)
{   if(n==m){return(1);}
    static int a[100][100];
    if(n<m)
        swap(&n,&m);
    if(a[n][m])
        return a[n][m];
    int x = INT_MAX,i;

    for(i=1;i<=n/2;i++)
    {
        x = min(x,findmin(i,m)+findmin(n-i,m));
    }
    for(i=1;i<=m/2;i++)
    {
        x = min(x, findmin(n,i)+findmin(n, m-i));
    }
    return(a[n][m]=x);
}
int min(int n, int m)
{
    return(n<m? n:m);
}

