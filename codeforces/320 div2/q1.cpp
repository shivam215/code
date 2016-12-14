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
    int n;
    scano(n);

    int a=1;
    while(n>1)
    {
        if(n%2==1)
        {

           a++;
           n=(n-1)/2;

        }
        else n=n/2;

    }
    printf("%d\n",a);

    return 0;
}
