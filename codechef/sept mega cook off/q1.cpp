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
map<string,int> m;
string s[100];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        for(int i=0;i<n;i++)cin>>s[i];
        m.clear();
        for(int i=0;i<k;i++)
        {
            int l;
            cin>>l;
            for(int i=0;i<l;i++)
            {
                string temp;
                cin>>temp;
                m[temp]=1;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(m[s[i]]==1)cout<<"YES"<<' ';
            else cout<<"NO"<<' ';
        }
        cout<<endl;
    }
    return 0;
}
