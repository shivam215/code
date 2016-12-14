#include <iostream>
#include <stdio.h>
using namespace std;
int a[100005],M[20][100005];
int p[20],g[100005],n;
void process2()
  {
      int i, j,x,y;

  //initialize M for the intervals with length 1
      for (i = 0; i < n; i++)
          M[0][i] = i;
  //compute values from smaller to bigger intervals
      for (j = 1;p[j]<=n; j++)
          for (i = 0; i+p[j]<=n; i++)
          {
               x = M[j-1][i];
              y = M[j-1][i+p[j-1]];
              M[j][i]=x;
              if(a[y]>a[x])M[j][i]=y;
          }
  }
int main()
{
    ios_base::sync_with_stdio(false);
    int m,x,y,i,j,l,r,z,pr,mx;
    //scanf("%d",&n);
    cin>>n;
    int c[n+100],d[n+100];
    for(i=0;i<n+100;i++)
    {
        c[i] = i;
        while(c[i]>=n-1)c[i] = c[i]-(n-1);
        d[i] = i;
        while(d[i]>=n)d[i] = d[i]-n;
    }
    //for(i=0;i<n;i++)scanf("%d",&a[i]);
    for(i=0;i<n;i++)cin>>a[i];
    p[0]=1;
    for(i=1;i<18;i++)p[i] = p[i-1]<<1;
    g[1]=0;
    for(i=2;i<100001;i++)g[i] = g[i>>1] + 1;
    process2();
    cin>>m>>x>>y;
    //scanf("%d%d%d",&m,&x,&y);
    long long sum = 0;
    for(i=1;i<=m;i++)
    {
        l=x;r=y;
        if(y<x){l=y;r=x;}
        z = g[r-l+1];
        pr = p[z];
        mx = M[z][l];
        if(a[M[z][l]]<a[M[z][r-pr+1]])mx = M[z][r-pr+1];
        sum = sum + a[mx];
        x = c[x+7];
        y = d[y+11];
    }
    printf("%lld\n",sum);

    return 0;
}
