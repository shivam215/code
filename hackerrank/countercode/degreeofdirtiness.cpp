#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,rem,quo,ans1,ans2;
        cin>>n>>m;
        if(n%2==0)
        {
            rem = m%n;
            quo = m/n;
            ans2 = quo-(rem==0);
            if(rem==0)rem=n;
            if(rem&1)ans1 = rem/2+1;
            else ans1 = n-rem/2+1;

        }
        else
        {
            rem = m%(2*n);
            quo = m/(2*n) - (rem==0);
            if(rem==0)rem=2*n;
                if(rem<=n)
                {
                    ans2 = 2*quo;
                    if(rem&1)ans1 = rem/2+1;
                    else ans1 = n-rem/2+1;
                }
                else
                {
                    ans2 = 2*quo + 1;
                    rem = rem - n;
                    if(rem&1)ans1 = n-rem/2;
                    else ans1 = rem/2;
                }
        }
        cout<<ans1<<' '<<ans2<<endl;
    }
    return 0;
}
