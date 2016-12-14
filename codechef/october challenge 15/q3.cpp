#include <bits/stdc++.h>
#define inf 1000000000
#define EPSILON 1.0/12.0
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
    int t;
    cin>>t;
    set< pii > ans;
    while(t--)
    {
        ans.clear();
        double a;
        cin>>a;
        for(int i=0;i<12;i++)
        {
            double j = (double)(30*i-a)*2.0;
            (j<0)continue;
            j = (j/11.0);
            int x = (int)(j);
            int y = (int)(j+1);
            if(x<=59)
            {
                double angle = (30.0*i-11.0*x/2.0);
                if(fabs(angle-a)<EPSILON)ans.insert(pii(i,x));
            }
            if(y<=59)
            {
                double angle = (30.0*i-11.0*y/2.0);
                if(fabs(angle-a)<EPSILON)ans.insert(pii(i,y));
            }
        }
        for(int i=0;i<12;i++)
        {
            double j = (double)(30*i+a)*2.0;
            if(j<0)continue;
            j = (j/11.0);
            int x = (int)(j);
            int y = (int)(j+1);
            if(x<=59)
            {
                double angle = (11.0*x/2.0-30*i);
                if(fabs(angle-a)<EPSILON)ans.insert(pii(i,x));
            }
            if(y<=59)
            {
                double angle = (11.0*y/2.0-30*i);
                if(fabs(angle-a)<EPSILON)ans.insert(pii(i,y));
            }
        }
        for(int i=0;i<12;i++)
        {
            double j = (double)(30*i-360+a)*2.0;
            if(j<0)continue;
            j = j/11;
            int x = (int)(j);
            int y = (int)(j+1);
            if(x<=59)
            {
                double angle = (30.0*i-11.0*x/2.0);
                if(fabs(angle-360+a)<EPSILON)ans.insert(pii(i,x));
            }
            if(y<=59)
            {
                double angle = (30.0*i-11.0*y/2.0);
                if(fabs(angle-360+a)<EPSILON)ans.insert(pii(i,y));
            }
        }
        for(int i=0;i<12;i++)
        {
            double j = (double)(30*i+360-a)*2.0;
            if(j<0)continue;
            j = j/11;
            int x = (int)(j);
            int y = (int)(j+1);
            if(x<=59)
            {
                double angle = (11.0*x/2.0-30*i);
                if(fabs(angle-360+a)<EPSILON)ans.insert(pii(i,x));
            }
            if(y<=59)
            {
                double angle = (11.0*y/2.0-30*i);
                if(fabs(angle-360+a)<EPSILON)ans.insert(pii(i,y));
            }
        }
        set< pii >::iterator it;
        for(it=ans.begin();it!=ans.end();it++)
        {
            printf("%02d:%02d\n",(*it).fe,(*it).se);
        }
    }
    return 0;
}
