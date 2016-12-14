#include <bits/stdc++.h>
#define inf 100000000
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
int a[105];
stack<int> st[105][105];
int main()
{
    freopen("q3l.in","r",stdin);
    freopen("q3l.out","w",stdout);
    int t;
    cin>>t;
    rep(test,1,t+1)
    {
        int n,k;
        cin>>n>>k;
        rep(i,0,n)cin>>a[i];
        rep(i,0,105)rep(j,0,105)while(!st[i][j].empty())st[i][j].pop();
        rep(i,0,n)st[i][i].push(a[i]);
        rep(i,0,n-1)
        {
            st[i][i+1].push(a[i+1]);
            st[i][i+1].push(a[i]);
        }
        rep(i,0,n-2)
        {
            if(!(a[i+2]-a[i+1]==k && a[i+1]-a[i]==k))
            {
                st[i][i+2].push(a[i+2]);
                st[i][i+2].push(a[i+1]);
                st[i][i+2].push(a[i]);
            }
        }
        for(int len=4;len<=n;len++)
        {
            for(int i=0;i<n-len+1;i++)
            {
                int j = i+len-1;
                if(st[i+1][j].size()>=2)
                {
                    int f = st[i+1][j].top();
                    st[i+1][j].pop();
                    int g = st[i+1][j].top();
                    st[i+1][j].pop();
                    st[i+1][j].push(g);
                    st[i+1][j].push(f);
                    st[i][j] = st[i+1][j];
                    if(g-f==k && f-a[i]==k)
                    {
                        st[i][j].pop();st[i][j].pop();
                    }
                    else st[i][j].push(a[i]);

                }
                else
                {
                    st[i][j] = st[i+1][j];
                    st[i][j].push(a[i]);
                }
                if(st[i+2][j].size()>=1)
                {
                    int f = st[i+2][j].top();
                    stack<int> temp = st[i+2][j];
                    if(f-a[i+1]==k && a[i+1]-a[i]==k)
                    {
                        temp.pop();
                    }
                    else
                    {
                        temp.push(a[i+1]);
                        temp.push(a[i]);
                    }
                    if(temp.size()<st[i][j].size())
                    {
                        st[i][j] = temp;
                    }
                }
                else
                {
                    stack<int> temp = st[i+2][j];
                    temp.push(a[i+1]);
                    temp.push(a[i]);
                    if(temp.size()<st[i][j].size())
                    {
                        st[i][j] = temp;
                    }
                }
                stack<int> temp = st[i+3][j];
                if(!(a[i+2]-a[i+1]==k && a[i+1]-a[i]==k))
                {
                    temp.push(a[i+2]);
                    temp.push(a[i+1]);
                    temp.push(a[i]);
                }
                if(temp.size()<st[i][j].size())
                {
                    st[i][j] = temp;
                }

            }
        }
        int ans = st[0][n-1].size();
        printf("Case #%d: %d\n",test,ans);
    }
    return 0;
}
