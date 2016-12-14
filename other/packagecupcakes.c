#include <stdio.h>
int main()
{
    int T,i;
    scanf("%d",&T);

    for(i=1;i<=T;i++)
    {
       int N;
       scanf("%d",&N);
       printf("%d\n",(N/2)+1);
    }
    return(0);
}
