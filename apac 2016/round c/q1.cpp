#include <bits/stdc++.h>
#define inf 1000000000
#define mod 1000000007
#define scano(x) scanf("%d",&x)
#define scanll(x) scanf("%lld",&x)
#define scant(x,y) scanf("%d%d",&x,&y)
#define pb push_back
#define mp make_pair
#define ll long long int
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fe first
#define se second
using namespace std;
map<string,vector<int> > m;
vector<pair<int,string> > vec;
int a[1003];
bool comp(pair<int,string> x,pair<int,string> y)
{
    if(x.fe!=y.fe)return x.fe>y.fe;
    return x.se<y.se;
}
int main()
{
    freopen("q1.in","r",stdin);
    freopen("q1.out","w",stdout);
    int t;
    cin>>t;
    for(int test=1;test<=t;test++)
    {
        int c=0;
        vec.clear();
        m.clear();
        int p;
        cin>>p;
        for(int i=0;i<p;i++)cin>>a[i];
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int w;
            cin>>w;
            for(int j=0;j<p;j++)
            {
                string str;
                cin>>str;
                m[str].pb(a[j]*w);
            }
        }
        int temp;
        cin>>temp;
        map<string,vector<int> >::iterator it;
        for(it=m.begin();it!=m.end();it++)
        {
            string str = it->first;
            vector<int> v = it->second;
            sort(v.begin(),v.end(),greater<int>());
            int sum=0;
            for(int i=0;i<v.size()&&i<temp;i++)
            {
                sum = sum + v[i];
            }
            vec.pb(mp(sum,str));
        }
        sort(vec.begin(),vec.end(),comp);
        printf("Case #%d:\n", test);
        int last=0;
        rep(i,0,vec.size())
        {
            if(i==0||vec[i].fe<vec[i-1].fe){last=i+1;}

            printf("%d: %s\n", last, vec[i].se.c_str());

        }
    }
    return 0;
}
