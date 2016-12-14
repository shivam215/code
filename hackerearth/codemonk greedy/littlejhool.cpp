#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int a[1000001];
int main()
{   int n,k;
    int ma,mi,t;
    cin>>t;
    while(t--)
    {   ma=0;
       mi=INT_MAX;
        cin>>n>>k;
        rep(i,0,n)
        cin>>a[i];

        sort(a,a+n);

        rep(i,0,(n/2)+1)
        {
            ma=max(ma,a[i]+a[n-i-1]);
            mi=min(mi,a[i]+a[n-i-1]);
        }
        cout<<ma-mi<<"\n";
        if((ma-mi)==k)
            cout<<"Lucky chap!\n";
        else if((ma-mi)>k)
            cout<<"No more girlfriends!\n";
        else cout<<"Chick magnet Jhool!\n";

    }
    return 0;
}
