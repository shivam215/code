#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll unsigned long long
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int main()
{
    long double d1,d2,n;
    cin>>d1>>d2>>n;
    if(d1<=0 || d2<=0 || n<=0)
    {
        cout<<"Invalid Input"<<endl;
        return 0;
    }
    long double ans;
    ans = sqrt(d2*n)*sqrt(d2*n+2*d1);
    cout<<fixed<<setprecision(11)<<ans<<endl;
    //printf("%.11f\n",ans);
    return 0;

}
