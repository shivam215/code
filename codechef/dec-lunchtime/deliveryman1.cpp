#include <bits/stdc++.h>
using namespace std;
struct s
{
    int a;
    int b;
    int c;
};
bool cmp(struct s s1, struct s s2)
{
    return s1.c>s2.c;
}
int main()
{
    int n,x,y,a,b,i;
    long long sum;
    cin>>n>>x>>y;
    struct s v[100005];
    for(i=0;i<n;i++)
    {
        cin>>v[i].a;
    }
    for(i=0;i<n;i++)
    {
        cin>>v[i].b;
        v[i].c = abs(v[i].a - v[i].b);
    }
    sort(v,v+n,cmp);
    //for(i=0;i<n;i++)cout<<v[i].c<<endl;
    a=0;b=0;sum=0;
    for(i=0;i<n;i++)
    {
       if(v[i].a>v[i].b)
       {
           if(a<x)
           {
               sum = sum + v[i].a;
               a++;
           }
           else if(b<y)
           {
               sum = sum + v[i].b;
               b++;
           }
       }
       else
       {
           if(b<y)
           {
               sum = sum + v[i].b;
               b++;
           }
           else if(a<x)
           {
               sum = sum + v[i].a;
               a++;
           }
       }
    }
    cout<<sum<<endl;
    return(0);

}
