#include <bits/stdc++.h>
#define inf 100000000
#define mod 761238923
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
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int res=0;
        for(int i=1;i<=n;i++)
        {
            int temp;
            cin>>temp;
            if(temp&1)res=res^i;
        }
        if(res==0)cout<<"Hanks Wins"<<endl;
        else cout<<"Tom Wins"<<endl;
    }
    return 0;
}
