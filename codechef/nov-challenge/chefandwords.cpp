#include <bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;
using namespace std;
struct matrix
{
    double data[26][26];
};
matrix mul(matrix a, matrix b)
{
    matrix c;
    memset(c.data,0,sizeof(double)*676);
    loop(i,0,26)
        loop(j,0,26)
            loop(k,0,26)
                c.data[i][j] += (a.data[i][k]*b.data[k][j]);
    return c;
}
matrix pow(matrix a, ll p)
{
    if(p==1)return a;
    matrix m = pow(a,p>>1);
    matrix m1 = mul(m,m);
    if(p&1)return mul(m1,a);
    else return m1;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t,n,m;
    ll k;
    double ans,temp;
    string s,f;
    matrix prob;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        cin>>s;
        loop(i,0,26)loop(j,0,26)cin>>prob.data[i][j];
        prob = pow(prob,k);
        ans=0;
        map<string,bool> done;
        while(n--)
        {
            temp=1;
            cin>>f;
            if(done[f])continue;
            m = f.size();
            if(s.size()==m)
            {
                loop(i,0,m)
                    temp *= (prob.data[s[i]-97][f[i]-97]);
                ans+=temp;
                done[f] = true;
            }
        }
        cout<<fixed<<setprecision(10)<<ans<<endl;
    }
    return(0);
}
