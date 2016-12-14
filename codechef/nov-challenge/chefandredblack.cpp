#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);cin.tie(0);
using namespace std;
int main()
{
    int Q,x,y,color=0,a,b,e,node,level;
    string q;
    cin>>Q;
    while(Q--)
    {
       cin>>q;
       if(q=="Qi")
       {
           color = color^1;
       }
       else
       {
       cin>>x>>y;
       a = (x>y)?y:x;
       b = (x>y)?x:y;
       e=0;
       while(a!=b)
       {
           if(a>b)
           {
               a>>=1;
           }
           else
           {
               b>>=1;
           }
           e++;
       }
       node = ++e;
       a = (x>y)?y:x;
       level=0;
       while(a!=0)
       {
           a = a>>=1;
           level++;
       }
       //cout<<node<<endl<<level;
       if(node%2==0)
       {
           cout<<(node/2)<<endl;
       }
       else
       {
           if(q=="Qb")
           {
              cout<<(node/2 + (color^(level&1)))<<endl;
           }
           else
           {
               cout<<(node/2+ (color^(!(level&1))))<<endl;
           }
       }

    }
    }
}
