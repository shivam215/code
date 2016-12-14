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
       mergesort(a,low,mid);
       mergesort(a,mid+1,high);
       merge(a,low, mid,high);
   }
}
int main()
{
    int T,i,j;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {   int N,count=0,k=0,l=0;
        scanf("%d",&N);
        int a[N],b[N];
        for(j=0;j<N;j++)
        {
            scanf("%d",&a[j]);
        }
        for(j=0;j<N;j++)
        {
            scanf("%d",&b[j]);
        }
        mergesort(a,0,N-1);
        mergesort(b,0,N-1);
        while(l<N && k<N)
        {
           if(a[k]<=b[l])
           {
               count++;
               k++;
               l++;
           }
           else
           {
               l++;
           }
        }
        printf("%d\n",count);

    }
    return(0);
}
