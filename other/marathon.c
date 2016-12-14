#include <stdio.h>
#define MAX 100007
int main()
{
    int T,i,n,Q,a,b,j;
    long long int sum;
    long long int arr[MAX];
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%d",&n);
        for(j=0;j<n;j++)
        {
            scanf("%d",&arr[j]);
        }
        for(j=1;j<n;j++)
        {
            arr[j] = arr[j]+arr[j-1];
        }
        scanf("%d",&Q);

        for(j=1;j<=Q;j++)
        {
         scanf("%d",&a);
         scanf("%d",&b);
         sum = arr[b] - arr[a];
         printf("%lld\n",sum);
         }
         printf("\n");

    }
    return(0);

}
