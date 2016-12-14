#include <bits/stdc++.h>
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
map<string,int> ma;
string str[105];
int n;
int check()
{
    int flag=1;
    for(int i=0;i<n-1;i++)
    {
        if(((ma[str[i]]-ma[str[i+1]]+10)%10)!=1)flag=0;
    }
    return (flag==1);

}
int main()
{
    int t,i,j,flag,val;
    map<string,int>::iterator it;
    string ans;
    vector<int> vec;
    string s[105];
    cin>>t;
    ma["1111110"]=0;
    ma["0110000"]=1;
    ma["1101101"]=2;
    ma["1111001"]=3;
    ma["0110011"]=4;
    ma["1011011"]=5;
    ma["1011111"]=6;
    ma["1110000"]=7;
    ma["1111111"]=8;
    ma["1111011"]=9;
    rep(test,1,t+1)
    {
        cin>>n;
        for(i=0;i<n;i++)cin>>s[i];
        if(n==1)
        {
            if(ma.find(s[0])!=ma.end())
            {
                val = ma[s[0]];
                val = (val-1+10)%10;
                for(it=ma.begin();it!=ma.end();it++)
                {
                    if(it->second==val)
                    {
                        cout<<"Case #"<<test<<": "<<it->first<<endl;
                        break;
                    }
                }
            }
            else
            {
                cout<<"Case #"<<test<<": ERROR!"<<endl;
            }
            continue;
        }
        vec.clear();

        for(i=0;i<7;i++)
        {
            flag=0;
            for(j=0;j<n;j++)
            {
                if(s[j][i]!='0')flag=1;
            }
            if(flag==0)vec.push_back(i);
        }
        for(i=0;i<vec.size();i++)cout<<vec[i]<<endl;
        flag=0;
        for(i=0;i<(1<<vec.size());i++)
        {
            for(int k=0;k<n;k++)str[k] = s[k];
            for(j=0;j<vec.size();j++)
            {
                if(i&(1<<j))
                {
                    for(int k=0;k<n;k++)
                    {
                        str[k][vec[j]]='1';
                    }
                }
            }
            for(int k=0;k<n;k++)cout<<str[k]<<endl;
            cout<<check()<<endl;
            if(check()==1)
            {
                flag=1;break;
            }
        }
        if(flag)
        {
            val = ma[str[n-1]];
            val = (val-1+10)%10;
            for(it=ma.begin();it!=ma.end();it++)
            {
                if(it->second==val)
                {
                    ans = it->first;
                }
            }
            for(j=0;j<vec.size();j++)
            {
                if(i&(1<<j))
                {
                    ans[vec[j]]='0';
                }
            }
            cout<<"Case #"<<test<<": "<<ans<<endl;

        }
        else
        {
            cout<<"Case #"<<test<<": ERROR!"<<endl;
        }

    }
    return 0;
}
