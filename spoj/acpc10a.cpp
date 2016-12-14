#include <bits/stdc++.h>
#define inf 1000000000
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
    while(1)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        if(a==0&&b==0&&c==0)break;
        if(a==b && b==c)
        {
            cout<<"GP"<<' '<<a<<endl;
            continue;
        }
        if(a+c==2*b)
        {
            cout<<"AP"<<' '<<c+(b-a)<<endl;
            continue;
        }
        cout<<"GP"<<' '<<c*(b/a)<<endl;
    }
    return 0;
}
