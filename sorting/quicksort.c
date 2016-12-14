#include <stdio.h>
int n;
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b= t;
}
int part(int* a,int l, int h)
{
    int piv = a[l];
    int i = l;
    while(l<h)
    {
        /*while(a[l]<=piv)l++;
        while(a[h]>piv)h--;
        if(l<h)swap(&a[l],&a[h]);*/
        if(a[l]<=piv)
            l++;
        else if(a[h]>piv)
            h--;
        else if(l<h)swap(&a[l],&a[h]);
    }
    swap(&a[i],&a[h]);
    return(h);
}
void quicksort(int* a,int low,int high)
{
   int pivot;
   if(low==high)
   {
       return;
   }
   if(low<high)
   {
       pivot = part(a,low,high);
       printf("%d\n",pivot);
       quicksort(a,low,pivot-1);
       quicksort(a,pivot+1,high);
   }
}
int main()
{
    int i;
    printf("enter n");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    quicksort(a,0,n-1);
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
    return(0);
}


