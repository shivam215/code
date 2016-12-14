#include <stdio.h>
#define ll long long
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        ll f,b,t,d,time;
        scanf("%lld%lld%lld%lld",&f,&b,&t,&d);
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
        printf("%lld",time);
    }
    return 0;
}

