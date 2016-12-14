#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int last[1002][30];
int main()
{
    string a,b;
    int i,j,n1,n2;
    while(1)
    {
        cin>>a>>b;
        if(a[0]=='*' && b[0]=='*')break;
        n1=a.size();
        n2 = b.size();
        for(i=0;i<=n2;i++)dp[0][i]=i;
        for(i=0;i<=n1;i++)dp[i][0]=i;
        memset(last,-1,sizeof(last));
        for(i=1;i<=n1;i++)
        {
            for(j=0;j<26;j++)
            {
                last[i][j] = last[i-1][j];
            }
            last[i][a[i-1]-'a']=i;
        }

        for(i=1;i<=n1;i++)
        {
            for(j=1;j<=n2;j++)
            {
                dp[i][j] = min(1+min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]+(a[i-1]!=b[j-1]));
                if(i>=2&&j>=2)
                {
                    if(a[i-1]!=b[j-1] && a[i-1]==b[j-2])
                    {
                        if(last[i][b[j-1]-'a']!=-1)
                        {
                            int x = last[i][b[j-1]-'a'];
                            dp[i][j] = min(dp[i][j],i-x+dp[x-1][j-2]);
                        }
                    }
                }
            }
        }
        cout<<dp[n1][n2]<<endl;
    }


    return 0;
}
