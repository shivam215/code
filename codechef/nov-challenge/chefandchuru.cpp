#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);cin.tie(0);
using namespace std;
int main()
{
    int N,a[100000],i,Q,d,x,y,m,n,j,rem;
    long long res;
    int L[100000],R[100000];
    cin>>N;
    long long b[N+1],F[N+1],s[N+1];
    b[0]=0;
    s[0]=0;
    for(i=0;i<N;i++)
    {
        cin>>a[i];
        if(i>=1)
            b[i] = b[i-1]+a[i-1];
    }
    b[N] = b[N-1]+a[N-1];
    for(i=0;i<N;i++)
    {
        cin>>L[i]>>R[i];
        F[i] = (b[R[i]] - b[L[i]-1]);
        if(i>=1){s[i] = s[i-1]+F[i-1];}
    }
    s[N] = s[N-1]+F[N-1];
    cin>>Q;
    while(Q--)
    {
        cin>>d;
        if(d==1)
        {
           cin>>x>>y;
           rem = y-a[x-1];
           a[x-1] = y;
           for(i=0;i<N;i++)
           {
               if(x>=L[i] && x<=R[i])
               {
                   F[i] = F[i]+rem;
               }
               if(i>=1)
               {
                   s[i] = s[i-1]+F[i-1];
               }
           }
           s[N] = s[N-1]+F[N-1];

        }
        else
        {
            cin>>m>>n;
            res = s[n]-s[m-1];
            cout<<res<<endl;
        }
    }
    return(0);

}
