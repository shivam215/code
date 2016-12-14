#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll G,T,A,D;
    while(1){
            scanf("%lld%lld%lld%lld",&G,&T,&A,&D);

            if(G==-1) break;

            int i=0;
            ll x = 0,y, temp;
            x += (G*T*(T-1))/2;
            temp = G*A + D;
            while((1LL<<i)<temp)
            {
                i++;
            }
            y = (1LL<<i) - temp;
            x += (1LL<<i) - 1;
            printf("%lld*%lld/%lld+%lld=%lld+%lld\n",G,A,T,D,x,y);
    }
    return 0;
}

