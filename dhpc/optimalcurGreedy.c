#include <stdio.h>
int optimal(int n, int m);
int main()
{
    int T,i,n,m,temp,result;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%d",&n);
        scanf("%d",&m);
        if(n>m)
        {
            temp = n;
            n = m;
            m = temp;
        }
        result = optimal(n,m);
        printf("%d\n",result);

    }
    return(0);
}
int optimal(int n, int m)
{
    if(n==m)
        return(1);
    if(m%n==0)
        return(m/n);
    return((m/n)+optimal(m%n,n));

}

