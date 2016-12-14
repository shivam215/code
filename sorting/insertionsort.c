#include <stdio.h>
void insertionsort(int* a,int n);
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
    insertionSort(a,n);
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}
void insertionSort(int A[], int size)
{
   int i, key, j;
   for (i = 1; i < size; i++)
   {
       key = A[i];
       j = i-1;
       while (j >= 0 && A[j] > key)
       {
           A[j+1] = A[j];
           j = j-1;
       }
       A[j+1] = key;
   }
}
