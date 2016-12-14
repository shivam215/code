#include <stdio.h>
int findsecond(int arr[],int first,int size)
{
    int j,second,k;
    second = first+1;
    for(k=second+1;k<size;k++)
    {
       if(arr[k]>arr[first] && arr[k]<arr[second])
       {
           second = k;
       }
    }
    return second;
}
void swap(int *a, int *b)
{
    int t;
     t = *a;
    *a = *b;
    *b = t;
}
void reverse(int a[], int l, int h)
{
    while(l<h)
    {
        swap(&a[l],&a[h]);
        l++;
        h--;
    }
}
int main()
{
    int n,i,second;
    printf("enter n");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=n-2;i>=0;i--)
    {
        if(a[i]<a[i+1]){break;}
    }
    second = findsecond(a,i,n);
    swap(&a[i],&a[second]);
    reverse(a,i+1,n-1);
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    return(0);

}
