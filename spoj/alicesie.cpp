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
#define MAX 1000006
using namespace std;
/*To cancel number x there should be present at least 2*x in the series*/
int main()
{
    int t;
    scano(t);
    while(t--)
    {
        int n;
        scano(n);
        if(n&1)
        {
            cout<<(n/2+1)<<endl;
        }
        else
            cout<<n/2<<endl;

    }
    return 0;
}
