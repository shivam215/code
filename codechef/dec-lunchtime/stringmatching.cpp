#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int n,m,cnt,i,j,k;
    string a,b;
    cin>>a;
    n = a.size();
    cin>>k;
    int v[100005];
    while(k--)
    {
        cin>>b;
        m = b.size();
        cnt=0;
        for(i=0;i<n-m+1;i++)
        {
            cnt=0;
            for(j=i;j<i+m;j++)
            {
                if(a[j]!=b[j-i])cnt++;
            }
            v[i]=cnt;
        }
        ll res = 0;
        for(i=0;i<n-m+1;i++)
        {
            res = (res*100001 + v[i])%mod;
        }
        cout<<res<<endl;

    }
    return 0;
}
