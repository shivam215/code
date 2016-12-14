#include <stdio.h>
void rearrange(int *a, int n)
{
    int i,j=0;
    for(i=0;i<n-1;i++)
    {
        if(a[i]==0)
            continue;
        else if(a[i]==a[i+1])
        {
            a[i]=a[i]+a[i+1];
            a[i+1]=0;
        }
    }
    for(i=0;i<n;i++)
    {
        if(a[i]>0)
        {
           a[j]=a[i];
           j++;
        }
    }
    for(i=j;i<n;i++)
    {
        a[i]=0;
    }

}
int main()
{
    int n,i;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    rearrange(a,n);
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    return(0);
}
