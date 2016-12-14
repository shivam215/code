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
string w[200],abr,abrs,wstr,abbr;
int n1,n2,len,total;
ll ways(int i,int j)
{
    if(i==n1)return 1;
    if(i!=n1&&j==n2)return 0;
    ll res=0;
    if(abrs[i]-'A'==wstr[j]-'a')
    {
        res += ways(i+1,j+1);
    }
    res += ways(i,j+1);
    return res;
}
ll solve(int i,int j)
{
    if(i==len)
    {
        if(j==total)return 1;
        return 0;
    }
    if(i!=len && j==total)return 0;
    ll sum=0;
    for(int k=1;k<=len-i;k++)
    {
        abrs = abr.substr(i,k);
        wstr = w[j];
        n1 = abrs.size();
        n2 = wstr.size();
        ll r1 = ways(0,0);
        ll r2 = solve(i+k,j+1);
        sum = sum + r1*r2;
    }
    return sum;

}
int main()
{
    while(1)
    {
        int n;
        cin>>n;
        if(n==0)break;
        m.clear();
        for(int i=0;i<n;i++)
        {
            string temp;
            cin>>temp;
            m[temp]=1;
        }
        string line;
        getline(cin, line);

        while (true) {
            getline(cin, line);

            istringstream iss(line);

            getline(iss, abbr, ' ');
            abr = abbr;
            len = abr.size();

            string word;
            getline(iss, word, ' ');

            if (abr == "LAST" && word == "CASE") break;
            total=0;

            do {
                if (!word.empty() && m.find(word) == m.end()) {
                    w[total++] = word;
                }
            } while (getline(iss, word, ' '));
            ll res = solve(0,0);
            if(res==0)cout<<abr<<" is not a valid abbreviation"<<endl;
            else cout<<abr<<" can be formed in "<<res<<" ways"<<endl;
        }
    }
    return 0;
}
