#include <bits/stdc++.h>
using namespace std;
int cnt[102];
int main()
{
    int n,m,temp,mx,in,i,j;
    cin>>n>>m;
    for(i=0;i<m;i++)
    {
        mx=INT_MIN;
        in=-1;
        for(j=0;j<n;j++)
        {
            cin>>temp;
            if(temp>mx)
            {
                mx = temp;
                in = j+1;
            }
        }
        cnt[in]++;
    }
    mx = INT_MIN;
    in = -1;
    for(i=1;i<=n;i++)
    {
        if(cnt[i]>mx)
        {
            mx = cnt[i];
            in = i;
        }
    }
    cout<<in<<endl;
    return 0;
}
