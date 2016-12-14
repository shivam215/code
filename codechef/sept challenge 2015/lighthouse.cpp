#include <bits/stdc++.h>
#define scano(x) scanf("%d",&x)
#define scant(x,y) scanf("%d%d",&x,&y)
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define piii pair< pii, int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fe first
#define se second
using namespace std;
vector< pii > point;
pii p[4];
int ind[4];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        point.clear();
        for(int i=0;i<n;i++)
        {
            int a,b;
            cin>>a>>b;
            if(i==0||a>p[0].fe||(a==p[0].fe&&b>p[0].se))
            {
                p[0].fe=a;p[0].se=b;ind[0]=i+1;
            }
            if(i==0||a>p[1].fe||(a==p[1].fe&&b<p[1].se))
            {
                p[1].fe = a;p[1].se=b;ind[1]=i+1;
            }
            if(i==0||a<p[2].fe||(a==p[2].fe&&b<p[2].se))
            {
                p[2].fe=a;p[2].se=b;ind[2]=i+1;
            }
            if(i==0||a<p[3].fe||(a==p[3].fe&&b>p[3].se))
            {
                p[3].fe=a;p[3].se=b;ind[3]=i+1;
            }
            point.push_back(mp(a,b));
        }
        for(int i=0;i<n;i++)
        {
            int a = point[i].fe;
            int b = point[i].se;
            if(p[0].se<b||p[0].fe<a)ind[0]=-1;
            if(p[1].se>b||p[1].fe<a)ind[1]=-1;
            if(p[2].se>b||p[2].fe>a)ind[2]=-1;
            if(p[3].se<b||p[2].fe>a)ind[3]=-1;
        }
        if(ind[0]!=-1)
        {
            cout<<ind[0]<<' '<<"SW"<<endl;
            continue;
        }
        if(ind[1]!=-1)
        {
            cout<<ind[1]<<' '<<"NW"<<endl;
            continue;
        }
        if(ind[2]!=-1)
        {
            cout<<ind[2]<<' '<<"NE"<<endl;
            continue;
        }
        if(ind[3]!=-1)
        {
            cout<<ind[3]<<' '<<"SE"<<endl;
            continue;
        }
        piii u,v;
        for(int i=0;i<n;i++)
        {
            if(i==0||u.fe.fe<point[i].fe)
            {
                u = mp(point[i],i+1);
            }
            if(i==0||v.fe.fe>point[i].fe)
            {
                v = mp(point[i],i+1);
            }
        }
        if(u.fe.se<=v.fe.se)
        {
            cout<<2<<endl;
            cout<<u.se<<' '<<"NW"<<endl;
            cout<<v.se<<' '<<"SE"<<endl;
        }
        else
        {
            cout<<2<<endl;
            cout<<u.se<<' '<<"SW"<<endl;
            cout<<v.se<<' '<<"NE"<<endl;
        }

    }
    return 0;
}
