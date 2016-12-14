#include <bits/stdc++.h>
#define scanint(x) scanf("%d",&x)
#define scanll(x) scanf("%lld",&x)
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

int hs[100001];
int hb[100001];

int main()
{
    int n,s;
    cin>>n>>s;
    char c;
    int x,y;
    rep(i,0,n)
    {
       cin>>c;
       cin>>x>>y;

       if(c=='B')
            hb[x]=hb[x]+y;
       else
       {
           hs[x]=hs[x]+y;
       }
    }
    int c1=0,ansi=100000;
    for(int i=0;i<=100000;i++)
    {
        if(hs[i]!=0)c1++;
        if(c1==s)
        {
            ansi=i;
            break;
        }
    }

     for(int i=ansi;i>=0;i--)
    {
        if(hs[i]!=0)
        {
            cout<<'S'<<" "<<i<<" "<<hs[i]<<"\n";
        }
    }
    c1=0;
    for(int i=100000;i>=0;i--)
    {
        if(hb[i]!=0)
        {
            cout<<'B'<<" "<<i<<" "<<hb[i]<<"\n";
            c1++;
          //  cout<<c1<<" "<<s<<" ls\n";
            if(c1>=s)
                break;
        }
    }





    return 0;
}
