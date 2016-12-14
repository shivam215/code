#include <bits/stdc++.h>
#define mod 1000000009
using namespace std;
int main()
{   ios_base::sync_with_stdio(false);cin.tie(0);
    int T,N,M,i,ti,k,b;
    char ch;
    long long res;
    cin>>T;
    while(T--)
    {
        cin>>N>>M;
        char c[N];
        for(i=0;i<N;i++)
        {
            c[i]='.';
        }
        for(i=0;i<M;i++)
        {
            cin>>ch>>b;
            b--;
            c[b]=ch;
        }
        i=0;
        while(c[i]=='.' && i<N)i++;
        ti = i;
        k = c[i];
        res=1;
        while(i<N)
        {
           i++;
           while(c[i]=='.'&&i<N)i++;
           if(i<N)
           {
              if(c[i]!=k)
            {res = res*(i-ti);
             if(res>=mod){res%=mod;}
             k = c[i];
            }
            ti=i;
        }
        }
        cout<<res<<endl;
    }
    return(0);
}
