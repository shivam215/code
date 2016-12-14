#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);cin.tie(0);
#define res 1000000007
using namespace std;
int search(int* a, int l, int h, int key)
{
  for(int i=l;i<=h;i++)
  {
      if(a[i]==key)
        return i;
  }
  return -1;
}
int findbracket(int* a, int l, int h)
{
    int i=l,j=h;
    if(a[i]<0 && a[i] = -1*a[j])
        return 2*findbracket(a,i+1,h-1)
    else
    {
        while(a[i]>0 || a[i]!= (-1)*a[j])
        {
            while(a[i]>0){i++;}
            ind = search(a,i+1,h,-1*a[j])
            if(ind == -1)
                i++;
            else
            {
                break;
            }
        }
        temp1 = findbracket(a,i,ind);
        temp2 = findbracket(a,ind+1,h);
        return (temp1*temp2);
    }
}
int main()
{
    int N,a[101],i,k=0;
    cin>>N;
    for(i=0;i<N;i++)
    {
        cin>>a[i];
    }


}
