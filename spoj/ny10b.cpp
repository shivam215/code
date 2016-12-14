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
void baseb(int x,int base,vector<int> &v)
{
    while(x>0)
    {
        v.push_back(x%base);
        x/=base;
    }
}
int convert(vector<int> &vec,int base)
{
    int res=0,a=1;
    for(int i=0;i<vec.size();i++)
    {
        res = res + vec[i]*a;
        a = a*base;
    }
    return res;
}
int solve(int x, int y,int base)
{
    vector<int> a,b,vec;
    baseb(x,base,a);
    baseb(y,base,b);
    int i=0,j=0;
    //for(i=0;i<a.size();i++)
    while(i<a.size()||j<b.size())
    {
        if(i<a.size()&&j<b.size())
        {
            vec.push_back((a[i]+b[j])%base);
        }
        else if(i<a.size())
        {
            vec.push_back(a[i]);
        }
        else
        {
            vec.push_back(b[j]);
        }
        i++;j++;
    }
    return convert(vec,base);
}
int main()
{
    int t;
    scanint(t);
    while(t--)
    {
        int test,base,x,y;
        scanf("%d%d%d%d",&test,&base,&x,&y);
        int res = solve(x,y,base);
        printf("%d %d\n",test,res);
    }
    return 0;
}
