#include <bits/stdc++.h>
#define G 9.806
#define PI 3.14159265
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
int main()
{
    int t;
    cin>>t;
    rep(test,1,t+1)
    {
        double d,v;
        cin>>d>>v;
        double temp = (G*d)/(v*v);
        if(temp<-1 || temp>1){printf("Scenario #%d: -1\n",test);continue;}
        double res = asin(temp)*90.0/PI;
        printf("Scenario #%d: %.2f\n",test,res);
    }
    return 0;
}
