#include <stdio.h>
void selectionsort(int* a,int n);
int main()
{
    int n,i;
    printf("enter n");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    selectionsort(a,n);
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}
void selectionsort(int* a,int n)
{
    int i,j,min,temp;
    for(i=0;i<n-1;i++)
    {   min = i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
                min = j;
        }
        temp = a[min];
        a[min] = a[i];
        a[i] = temp;

    }
}
