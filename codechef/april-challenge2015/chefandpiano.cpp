#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int t,n,res,temp,cnt,i;
    string s;
    cin>>t;
    while(t--)
    {
        cin>>s;
        cin>>n;
        cnt=1;
        for(i=0;i<s.size();i++)
        {
            if(s[i]=='T')cnt+=2;
            else cnt+=1;
        }
        n = 12*n;
        res=0;
        temp = cnt;
        while(temp<=n)
        {
            res =  res+n-temp+1;
            temp = temp+cnt-1;
        }
        printf("%d\n",res);
    }
    return 0;
}
