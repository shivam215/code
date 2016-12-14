#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int n;
    ll num,num2,res,rem,ans,i;
    string a,b;
    cin>>n;
    while(n--)
    {
        cin>>a>>b;
        num=0;num2=0;
        for(i=a.size()-1;i>=0;i--)num = num*10 + a[i]-'0';
        for(i=b.size()-1;i>=0;i--)num2 = num2*10 + b[i]-'0';
        res = num + num2;
        ans=0;
        while(res!=0)
        {
            rem = res%10;
            ans = ans*10 + rem;
            res = res/10;
        }
        cout<<ans<<endl;
    }
    return 0;
}
