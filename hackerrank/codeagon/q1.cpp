#include <bits/stdc++.h>
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
    int n,s;
    cin>>n>>s;

    if (((n*(n+1))/2)<s)
    {
        cout<<"-1\n";
        return 0;
    }
    else if(s<=n)
    {

        cout<<"1\n";
        return 0;
    }
    else
    {   //cout<<"1\n";
        int ans=0;
        int flag=0;
        for(int i=n; i>=1; i--)
        {
            if(i>s)continue;

            s=s-i;
            ans++;
    //cout<<s<<" "<<ans<<"\n";
            if(s==0)
            {
                flag=1;
                cout<<ans<<"\n";
                return 0;
            }
           // cout<<s<<" "<<ans<<"\n";
        }
       // cout<<s<<" df\n";

    }

    return 0;
}
