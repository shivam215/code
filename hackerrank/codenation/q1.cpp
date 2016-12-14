#include <bits/stdc++.h>
#define inf 100000000
#define mod 1000000007
#define scano(x) scanf("%d",&x)
#define scanll(x) scanf("%lld",&x)
#define scant(x,y) scanf("%d%d",&x,&y)
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fe first
#define se second
using namespace std;
int main()
{
    int n,m;
    int a,b;
    int t;
    cin>>t;
    while(t--)
    {
        scant(n,m);
        if(n%2==0&&m%2==0)
        {
            a=(n+m-2)/2;
            b=(n+m-1)-a;

            if(a>b)
                cout<<"Player A wins"<<endl;
            else cout<<"Player B wins"<<endl;
        }
        else
        {


                a=(n+m-1)/2;
                b=(n+m-1)-a;

                if(a>b)
                    cout<<"Player A wins"<<endl;
                else cout<<"Player B wins"<<endl;

        }
    }
    return 0;
}
