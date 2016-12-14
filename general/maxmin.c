#include <stdio.h>
struct pair
{
    int max;
    int min;
};
struct pair getminmax(int arr[],int low, int high);
int main()
{
    int a[] = {12,3,6,4,9,2,1,11,14,13},n=9;
    struct pair minmax;
    minmax = getminmax(a,0,n);
    printf("min is %d",minmax.min);
    printf("max is %d",minmax.max);
    return(0);

}
struct pair getminmax(int arr[], int low, int high)
{
  int l;
  struct pair m,m1,m2,m3;
  if(low==high)
  {
     m.max = arr[low];
     m.min = arr[low];
     return m;
  }
  l = (low+high)/2;
  m1 = getminmax(arr,low,l);
  m2 = getminmax(arr,l+1,high);
  if(m1.max>=m2.max)
  {m3.max = m1.max;}
  else
  {
      m3.max = m2.max;
  }
  if(m1.min>=m2.min)
  {
      m3.min = m2.min;
  }
  else
  {
      m3.min = m1.min;
  }
  return m3;

}
