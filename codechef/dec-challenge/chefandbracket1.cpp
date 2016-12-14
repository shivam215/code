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
int main()
{
    int N,a[105],i,j,len,in,count,in1,in2;
    long long dp[101][101];
    cin>>N;
    for(i=0;i<N;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
        dp[i][j]=0;
        }
    }
    for(i=0;i<N-1;i++)
    {
        if(a[i]<0 && a[i]==(-1*a[i+1]))
            dp[i][i+1]=1;
    }
    len = 2;
    while(len<N)
    {
    for(i=0;i<N-len;i++)
    {
        if(a[i]<0&&a[i]==(-1*a[i+len]))
        {
            dp[i][i+len] = (2*dp[i+1][i+len-1]+1)%res;
        }
        else
        {
            dp[i][i+len] = (dp[i+1][i+len-1])%res;
        }

            in1 = -1;
            in2 = -1;
            if(a[i]<0)
            {
                in1 = search(a,i+1,i+len-1,(-1)*a[i]);
            }
            if(a[i+len]>0)
            {
                in2 = search(a,i+1,i+len-1,(-1)*a[i+len]);
            }
            if(in1!=(-1) && in2!=(-1))
            {
                dp[i][i+len] = (dp[i][i+len]+2+max(dp[i][in1]*dp[in1+1][i+len],dp[i][in2-1]*dp[in2][i+len]))%res;
            }
            else if(in1!=(-1))
            {
               dp[i][i+len] = (dp[i][i+len]+1+dp[i][in1]* dp[in1+1][i+len])%res;
            }
            else if(in2!=(-1))
            {
                dp[i][i+len] = (dp[i][i+len]+1+dp[i][in2-1]*dp[in2][i+len])%res;
            }
        /*else if(a[i+len]>0)
        {
            in = search(a,i,i+len-1,(-1*a[i+len]));
            if(in!=(-1))
            {
                count=0;
                for(j=i;j<=in-1;j++)
            {
                if(a[j]<0)
                {
                    if(search(a,in,i+len,(-1*a[j]))!=(-1))
                        count = (count + dp[i][j-1]+1)%res;
                }
            }

                dp[i][i+len] = (dp[i][in-1]*dp[in][i+len]+dp[i][in-1]+dp[in][i+len]+count)%res;
            }

            else
                dp[i][i+len] = (dp[i][i+len-1])%res;
        }
        else
            dp[i][i+len] = (dp[i][i+len-1])%res;*/
    }
    len++;
    }
    cout<<(dp[0][N-1]+1)%res<<endl;
    return(0);

}
