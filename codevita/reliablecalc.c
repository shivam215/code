#include <stdio.h>
#define ll long long
int main()
{
    ll n,f,t;
        scanf("%lld",&n);
        while(n<=0)
        {
            printf("Invalid Input\n");
            scanf("%lld",&n);
        }
        scanf("%lld",&f);
        while(f<0)
        {
            printf("Invalid Input\n");
            scanf("%lld",&f);

        }
        scanf("%lld",&t);
        while(t<=0)
        {
            printf("Invalid Input\n");
            scanf("%lld",&t);

        }
        if(f==0)
        {
            printf("Total Down Time: 0\n");
            printf("0\n");
            printf("0\n");
            printf("100%%");
            return 0;
        }
        double mb = (double)(n/f-t/f)+0.5;
        ll mtbf = (ll)(mb);
        double mr = (double)(t/f) + 0.5;
        ll mttr = (ll)(mr);
        //double av = ((double)mtbf/((double)mtbf+(double)mttr))*100 + 0.5;
        //ll aval = (ll)(av);
        printf("%lld\n",mtbf);
        printf("%lld\n",mttr);
        //printf("%lld%%",aval);

    return 0;
}

