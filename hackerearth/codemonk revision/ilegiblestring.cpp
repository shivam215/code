#include <bits/stdc++.h>
#define scano(x) scanf("%d",&x)
#define scant(x,y) scanf("%d%d",&x,&y)
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
    int n;
    string s;
    cin>>n>>s;
    int mx=0,mn=0;
    rep(i,0,s.size())
    {
        mx++;
        if(s[i]=='w')mx++;
    }
    rep(i,0,s.size())
    {
        if(i+1<s.size()&&s[i]=='v'&&s[i+1]=='v')
        {
            mn++;
            i++;
        }
        else if(i+1<s.size()&&s[i]=='v'&&s[i+1]=='w')
        {
            mn++;
            s[i+1]='v';
        }
        else
        {
            mn++;
        }
    }
    cout<<mn<<' '<<mx<<endl;
    return 0;
}
