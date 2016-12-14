#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        ll f,b,t,d,time;
        cin>>f>>b>>t>>d;
        if(d<=f)
        {
            time = t*d;
        }
        else
        {
            ll point,quo,rem,fin,total;
            point = d-f;
            quo = point/(f-b);
            rem = point%(f-b);
            fin = (quo+1-(rem==0))*(f-b);
            total = (quo+1-(rem==0))*(f+b) + d-fin;
            time = total*t;
        }
        cout<<time<<endl;
    }
    return 0;
}
