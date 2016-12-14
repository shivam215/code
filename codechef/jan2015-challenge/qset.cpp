#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m,i,j,c,d,type,len;
    long long sum,coun;
    cin>>n>>m;
    char a[n+1];
    int dp[n+1][n+1];
    cin>>a;
    for(i=0;i<n;i++)
    {
        if(a[i]%3==0)
            dp[i][i]=1;
        else
            dp[i][i]=0;
        for(j=i+1;j<n;j++)
        {
            dp[i][j]=0;
        }
    }
    len=1;
    while(len<n)
    {
        for(i=0;i<n-len;i++)
        {
            dp[i][i+len] = dp[i][i+len-1];
            sum=0;
            for(j=i+len;j>=i;j--)
            {
                sum = sum + a[j];
                if(sum%3==0)
                {
                    dp[i][i+len] = dp[i][i+len]+1;
                }
            }

        }
        len++;

    }
    /*for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("dp[%d][%d] = %d\n",i,j,dp[i][j]);
        }
    }*/
    while(m--)
    {
        cin>>type>>c>>d;
        c--;
        d--;
        cout<<dp[c][d]<<endl;

    }
    return(0);
}
