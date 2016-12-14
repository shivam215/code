#include <stdio.h>
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
            k++;
        }
        else
        {
            a[k]=L[i];
            i++;
            k++;
        }
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
       mergesort(a,0,mid);
       mergesort(a,mid+1,high);
       merge(a,0,mid,high);
   }
}
void ismajority(int* a, int n)
{
    int count=1,i;
    for(i=0;i<n-1;i++)
    {
        if(a[i]==a[i+1])
            count++;
        else
            count = 1;
        if(count>2)
            {
                printf("\nelement found %d",a[i]);
                return;
            }}
    printf("element not found");
}
int main()
{
    int i,n;
    printf("enter n");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    mergesort(a,0,n-1);
    ismajority(a,n);
    return(0);

}
