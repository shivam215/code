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
int main()
{
    string a,b;
    int cnt0=0,cnt1=0;
    cin>>a>>b;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]=='0')cnt0++;
        else cnt1++;
    }
    for(int i=0;i<b.size();i++)
    {
        if(b[i]=='0')cnt0--;
        else cnt1--;
    }
    int cnt=0;
    if(cnt0==0&&cnt1==0)
    {
        for(int i=0;i<a.size();i++)
        {
            if(a[i]!=b[i])cnt++;
        }
        cout<<(cnt/2)<<endl;
    }
    else cout<<-1<<endl;
    return 0;
}
