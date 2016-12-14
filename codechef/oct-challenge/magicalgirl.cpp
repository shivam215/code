#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);cin.tie(0);
using namespace std;
int main()
{
    int T,R,G,B,M,i,m;
    int r[101],g[101],b[101],max1,max2,max3;
    cin>>T;
    while(T--)
    {
        cin>>R>>G>>B>>M;
        for(i=0;i<R;i++)
        {
            cin>>r[i];
        }
        for(i=0;i<G;i++)
        {
            cin>>g[i];
        }
        for(i=0;i<B;i++)
        {
            cin>>b[i];
        }
        max1=r[0];
        for(i=0;i<R;i++)
        {
            if(r[i]>max1)
                max1=r[i];
        }
        max2=g[0];
        for(i=0;i<G;i++)
        {
            if(g[i]>max2)
                max2=g[i];
        }
        max3=b[0];
        for(i=0;i<B;i++)
        {
            if(b[i]>max3)
                max3=b[i];
        }
        for(i=0;i<M;i++)
        {
            m = max(max1,max(max2,max3));
            if(max1==m)
                max1 = m/2;
            else if(max2==m)
                max2 = m/2;
            else
                max3 = m/2;
        }
        cout<<max(max1,max(max2,max3))<<endl;
    }
    return(0);
}
