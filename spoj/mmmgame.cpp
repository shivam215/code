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
    int t;
    cin>>t;
    while(t--)
    {
        int temp,n,ans=0;
        cin>>n;
        for(int i=0;i<n;i++){cin>>temp;if(temp==1)temp=0;ans=ans^temp;}
        if(ans==0)cout<<"Brother"<<endl;
        else cout<<"John"<<endl;
    }
}
