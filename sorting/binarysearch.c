#include <stdio.h>
int binarysearch(int* a, int l, int h, int key)
{
    int mid;
    while(l<=h)
    {
        mid = (l+h)/2;
        if(a[mid]==key)
            return 1;
        else if(a[mid]>key)
            h = mid-1;
        else
            l = mid+1;
    }
    return -1;
}
int main()
{
    int i,n,key,result;
    printf("enter n");
    scanf("%d",&n);
    int a[n];
    printf("enter %d elements",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("enter key to be searched");
    scanf("%d",&key);
    result = binarysearch(a,0,n-1,key);
    (result==-1)?printf("element is not present"):printf("element found");
    return(0);

}
