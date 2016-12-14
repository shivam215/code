#include <stdio.h>
void merge(int* a, int l, int m, int h);
void mergesort(int* a, int low, int high);
int main()
{
    int n,i;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    mergesort(a,0,n-1);
    for(i=0;i<n;i++)
        printf("%d\n",a[i]);
    return(0);
}
void merge(int* a, int l, int m, int h)
{
    int n1= m-l+1;
    int n2 = h-m;
    int L[n1],R[n2],i,j;
    for(i=0;i<n1;i++)
        L[i]=a[l+i];
    for(j=0;j<n2;j++)
        R[j]=a[m+1+j];
    i=0;
    j=0;
    int k=l;

    while(i<n1&&j<n2)
    {
        if(L[i]>R[j])
        {
            a[k]=R[j];
            j++;
        }
        else
        {
            a[k]=L[i];
            i++;
        }
        k++;
    }
    while(i<n1)
    {
        a[k]=L[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}
void mergesort(int* a, int low, int high)
{
   int mid;
   if(low==high)
        return;
   if(low<high)
   {   mid = (low+high)/2;
       mergesort(a,low,mid);
       mergesort(a,mid+1,high);
       merge(a,low,mid,high);
   }
}
