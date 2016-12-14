#include<bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef unsigned long long  ull;

ll mod= 1000000007;

#define fast      ios_base::sync_with_stdio(false);
#define frmlty     int test_case;cin>>test_case;while(test_case--)

#define vi        vector<int>
#define vs        vector<string>
#define vll       vector<ll>
#define pii       pair<int,int>

#define msi       map<string,int>
#define msit      map<string,int>::iterator
#define pb        push_back
#define mp        make_pair

#define loop(i,a,b)      for(int i=a;i<b;i++)
#define rloop(i,a,b)     for(int i=b-1;i>=a;i--)

#define gcd(a,b)  __gcd(a,b)
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))

#define le(x) scanf("%d",&x);
#define le2(x,y) scanf("%d%d",&x,&y);
#define lell(x) scanf(" %I64d",&x);
#define le2ll(x,y) scanf(" %I64d%I64d",&x,&y);

#define F first;
#define S second;

//cout<<fixed<<setprecision(6)<<ans<<"\n";

int isp[1001];
vi p;
vi ans1;

int h[1001][1001];
int ans[1001];
int main()
{
    int n;
    le(n);

    if(n==1)
    {

     cout<<"0\n";
     return 0;
    }for(int i=2; i<=n; i++)
    {
        if(isp[i]==0)
        {


            for(int j=i; j<=n; j=j+i)
            {
                isp[j]=1;
                h[j][i]=1;
            }
        }
    }


    for(int i=2; i<=n; i++)
    {
        int r=1;
        //cout<<i<<"\n";
        loop(j,2,i+1)
        {
            if(h[i][j]==1)r=r*j;
            //cout<<j<<" "<<h[i][j]<<"     ";
        }
        if(h[i][i]==1)
       ans1.pb(i);//     cout<<i<<" ";
        else if(r==i)
        {
            if(n>=i*2)
             ans1.pb(i);//   cout<<i<<" ";
        }
        else if(r!=i)
        {
        ans1.pb(i);//    cout<<i<<" ";
        }



    }

    cout<<ans1.size()<<"\n";
    loop(i,0,ans1.size())
    cout<<ans1[i]<<" ";
        cout<<"\n";


    return 0;
}
