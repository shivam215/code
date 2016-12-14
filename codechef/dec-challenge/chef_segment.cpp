#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);cin.tie(0);
using namespace std;
int main()
{
    int n,i,count;
    long long k,num,tem;
    long double res1,res2,res,x,temp,temp1;
    cin>>n;
    while(n--)
    {   count = 0;
        temp = 1;
        cin>>x>>k;
        tem = k;
        while((tem/2)!=0)
        {
            count++;
            tem = tem/2;
        }
        while(count!=0)
        {
            temp = temp*2;
            count--;
        }
        temp1 = (temp)*2;
        res1 = x/temp1;
        res2 = x/temp;
        num = k-temp;
        res = res1 + (num*res2);
        cout<<fixed<<res<<endl;

        }
        return(0);
}
