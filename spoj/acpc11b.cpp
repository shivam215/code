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
    int t;
    int a[1003],b[1003];
    cin>>t;
    while(t--)
    {
        int n1,n2;
        cin>>n1;
        for(int i=0;i<n1;i++)cin>>a[i];
        cin>>n2;
        for(int i=0;i<n2;i++)cin>>b[i];
        int mn=inf;
        for(int i=0;i<n1;i++)
        {
            for(int j=0;j<n2;j++)
            {
                if(mn>abs(a[i]-b[j]))mn=abs(a[i]-b[j]);
            }
        }
        cout<<mn<<endl;
    }
    return 0;
}
