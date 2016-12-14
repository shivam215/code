#include <stdio.h>
#include <stdlib.h>
int gcd(int a, int b);
int main()
{
    int T,n,k;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {   k=0;
        scanf("%d",&n);
        int a[n],b[n];
        for(j=0;j<n;j++)
        {
            scanf("%d\t",&a[i]);
        }
        while(k<n)
        {  l=0;
           b[l]=a[k];
           for(j=0;j<n;j++)
           {
              for(m=l;m>=0;m--)
              {
                  if(gcd(b[m],a[j])==1 && m==0)
                  {
                      l = l+1;
                      b[l]=a[j];
                      break;
                  }
                  if(gcd(b[m],a[j])!=1){break;}
                  if(gcd(b[m],a[j])==1){continue;}

              }
           }
        }
    }
}
