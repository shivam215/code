#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

//cout<<fixed<<setprecision(6)<<ans<<"\n";
int a[100001];
int ht[100001];
vi left1;

int main()
{
    int n;
    cin>>n;
    rep(i,1,n+1)
    {
        cin>>a[i];
    }

    rep(i,1,n+1)
    {
        if(ht[a[i]]==0&&a[i]<=n)
        {
            ht[a[i]]=1;
        }
        else{
        left1.pb(i);
        }
    }
    int c=0;
    rep(i,1,n+1)
    {
        if(ht[i]==0)
        {
            a[left1[c]]=i;
            c++;
        }
    }

    rep(i,1,n+1)
    printf("%d ",a[i]);

    printf("\n");

    return 0;
}
