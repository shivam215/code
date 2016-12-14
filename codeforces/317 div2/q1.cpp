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

int a[100001];
int b[100001];

int main()
{
    int n1,n2;
    cin>>n1>>n2;

    int k,m;
    cin>>k>>m;

    rep(i,1,n1+1)
    cin>>a[i];

    rep(i,1,n2+1)
    cin>>b[i];



    if(b[n2+1-m]>a[k])
        cout<<"YES\n";
    else
        cout<<"NO";


    return 0;
}
