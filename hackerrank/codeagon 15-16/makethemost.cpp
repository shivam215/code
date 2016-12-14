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
pii a[100005];
bool comp(pii c,pii d)
{
    if(c.se!=d.se)return c.se<d.se;
    return c.fe<d.fe;
}
int main()
{
    int n,p;
    cin>>n>>p;
    for(int i=0;i<p;i++)
    {
        string s1,s2;
        int inh=0,inm=0,outh=0,outm=0,in,out;
        cin>>s1>>s2;
        int j=0;
        while(s1[j]!=':')
        {
            inh = inh*10 + s1[j]-'0';
            j++;
        }
        j++;
        while(j<s1.size())
        {
            inm = inm*10 + s1[j]-'0';
            j++;
        }

        j=0;
        while(s2[j]!=':')
        {
            outh = outh*10 + s2[j]-'0';
            j++;
        }
        j++;
        while(j<s2.size())
        {
            outm = outm*10 + s2[j]-'0';
            j++;
        }
        if(inh<8)inh=inh+12;
        if(outh<8)outh = outh+12;
        in = (inh-8)*60+inm;
        if(outh==8&&outm==0)outh=20;
        out = (outh-8)*60+outm;
        a[i].fe=in;a[i].se=out;
        //cout<<in<<' '<<out<<endl;
    }
    sort(a,a+p,comp);
    //rep(i,0,p)cout<<a[i].fe<<' '<<a[i].se<<endl;
    int ans=0;
    set< pii > s;
    for(int i=0;i<p;i++)
    {
        if(s.size()==0)
        {
            s.insert(mp(a[i].se,i));
            ans++;
        }
        else
        {
            set< pii >::iterator it;
            it = s.lower_bound(mp(a[i].fe,-1));
            //cout<<(*it).first<<' '<<(*it).se<<endl;
            if(it==s.begin())
            {
                if((*it).fe==a[i].fe)
                {
                    s.erase(it);
                    s.insert(mp(a[i].se,i));
                    ans++;
                }
                else
                {
                if(s.size()<n)
                {
                    s.insert(mp(a[i].se,i));
                    ans++;
                }
                }
            }
            else
            {
                if(it!=s.end()&&(*it).fe==a[i].fe)
                {
                    s.erase(it);
                    s.insert(mp(a[i].se,i));
                    ans++;
                }
                else
                {
                it--;
                s.erase(it);
                s.insert(mp(a[i].se,i));
                ans++;
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;

}
