#include <stdio.h>
void bubblesort(int* a,int n);
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
    bubblesort(a,n);
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}
void bubblesort(int* a,int n)
{
    int i,j,flag;
    for(i=0;i<n-1;i++)
    {   flag = 0;
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                flag = 1;
            }
        }
        if(flag==0){break;}
    }
    }
