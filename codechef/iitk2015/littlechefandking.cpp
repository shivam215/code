#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll pow(ll a, ll b){ll x=1,y=a;while(b>0){if(b&1)x=x*y;y=y*y;b>>=1;}return x;}
int main()
{
    int t;
    long long n,k,i,j,cnt;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        if(k==1)
            {cout<<n<<endl;
        continue;}
        i=0;
        long long temp=n;
        while(temp/k!=0)
        {
            temp/=k;
            i++;
        }
        vector<long long> v;
        for(j=0;j<=i;j++)
        {
            v.push_back(pow(k,j));
        }
        temp=0;
        i = v.size()-1;
        cnt=0;
        while(temp!=n && i>=0)
        {
            temp = temp + (min(k,n/v[i]))*v[i];
            cnt = cnt + min(k,n/v[i]);
            n = n - (min(k,n/v[i]))*v[i];
            i--;

        }
        cout<<cnt<<endl;

    }
}
