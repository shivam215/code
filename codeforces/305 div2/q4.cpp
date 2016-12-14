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
#define MAX 200005
using namespace std;
ll ans[MAX],a[MAX];
int l[MAX],r[MAX];
int main()
{
    int n;
    cin>>n;
    rep(i,0,n)cin>>a[i];
    stack<int> st;
    rep(i,0,n)
    {
        if(st.empty())st.push(i);
        else
        {
            if(a[i]>=a[st.top()])st.push(i);
            else
            {
                while((!st.empty())&&(a[i]<a[st.top()]))
                {
                    int p = st.top();
                    r[p]=i;
                    st.pop();
                }
                st.push(i);
            }
        }
    }
    while(!st.empty())
    {
        r[st.top()]=n;
        st.pop();
    }
    for(int i=n-1;i>=0;i--)
    {
        if(st.empty())st.push(i);
        else
        {
            if(a[i]>=a[st.top()])st.push(i);
            else
            {
                while(!st.empty()&&a[i]<a[st.top()])
                {
                    int p = st.top();
                    l[p]=i;
                    st.pop();
                }
                st.push(i);
            }
        }
    }
    while(!st.empty())
    {
        l[st.top()]=-1;
        st.pop();
    }
    rep(i,0,n)
    {
        int sz = r[i]-l[i]-1;
        ans[sz] = max(ans[sz],a[i]);
    }
    for(int i=n-1;i>=1;i--)
    {
        ans[i] = max(ans[i],ans[i+1]);
    }
    rep(i,1,n+1)cout<<ans[i]<<' ';
    cout<<endl;
    return 0;

}

