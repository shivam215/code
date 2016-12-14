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
int a[3003],hs[2*3003];
int main()
{
    int n;
    cin>>n;
    rep(i,0,n){cin>>a[i];hs[a[i]]=1;}
    sort(a,a+n);
    int res=0;
    for(int i=1;i<n;i++)
    {
        if(a[i]==a[i-1])
        {
            int j = a[i]+1;
            while(hs[j])j++;
            hs[j]=1;
            res = res + j-a[i];
        }
    }
    cout<<res<<endl;
}
