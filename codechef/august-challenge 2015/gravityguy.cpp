#include <bits/stdc++.h>
#define inf 10000000
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t,dp1[200005],dp2[200005],i;
    string s1,s2;
    cin>>t;
    while(t--)
    {
        cin>>s1>>s2;
        int n = s1.size();
        /*if((s1[0]=='#'&&s2[0]=='#')||(s1[n-1]=='#'&&s2[n-1]=='#'))
        {
            printf("No\n");
            continue;
        }*/
        for(i=0;i<n;i++){dp1[i]=inf;dp2[i]=inf;}
        if(s1[0]=='.')dp1[0]=0;
        if(s2[0]=='.')dp2[0]=0;
        //cout<<dp1[0]<<' '<<dp2[0]<<endl;
        for(i=1;i<n;i++)
        {
            if(s1[i]=='.')
            {
                dp1[i] = dp1[i-1];
                if(dp2[i-1]!=inf)
                {
                    dp1[i] = MIN(dp1[i-1],dp2[i-1]+1);
                }
            }
            if(s2[i]=='.')
            {
                dp2[i] = dp2[i-1];
                if(dp1[i-1]!=inf)
                {
                    dp2[i] = MIN(dp2[i-1],dp1[i-1]+1);
                }
            }
            //cout<<dp1[i]<<' '<<dp2[i]<<endl;
        }
        int ans = MIN(dp1[n-1],dp2[n-1]);
        if(ans==inf)printf("No\n");
        else
        {
            printf("Yes\n");
            printf("%d\n",ans);
        }
    }
    return 0;
}
