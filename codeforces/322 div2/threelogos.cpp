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
    int a[6];
    rep(i,0,6)cin>>a[i];
    int res=0;
    res = a[0]*a[1] + a[2]*a[3] + a[4]*a[5];
    int st = sqrt(res);
    int flag=0;
    rep(i,-1,2)
    {
        if((st+i)*(st+i)==res)
        {
            flag=1;
            break;
        }
    }
    if(flag==0)cout<<-1<<endl;
    else
    {

    }

}
