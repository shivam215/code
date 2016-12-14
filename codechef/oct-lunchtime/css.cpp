#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
int main()
{
    int n,m;
    int a,b,c,d;
    map< pair<int,int>,int > value;
    map< pair<int,int>,int > priority;
    cin>>n>>m;
    while(n--)
    {
        cin>>a>>b>>c>>d;
        if(value[mp(a,b)]==0)
        {
            value[mp(a,b)]=c;
            priority[mp(a,b)]=d;
        }
        else
        {
            if(priority[mp(a,b)]<=d)
            {
                value[mp(a,b)]=c;
                priority[mp(a,b)]=d;
            }
        }
    }
    while(m--)
    {
        cin>>a>>b;
        cout<<value[mp(a,b)]<<endl;
    }
    return(0);
}
