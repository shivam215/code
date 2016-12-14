#include <stdio.h>
#define MAX 1000000
int main()
{
    int N,i,Q,n;
    scanf("%d",&N);
    int a[N];
    int *arr = malloc(MAX*sizeof(int));
    for(i=0;i<N;i++)
    {
        scanf("%d",&a[i]);
        arr[a[i]]++;

    }
    scanf("%d",&Q);
    for(i=1;i<=Q;i++)
    {
        scanf("%d",&n);
        printf("%d\n",arr[n]);
    }
    free(arr);
    return(0);

}
