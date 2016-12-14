#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int p[100005];
int main()
{
    int n;
    stack< pii > st;
    cin>>n;
    rep(i,0,n)
    {
        cin>>p[i];
    }
    st.push(pii(p[0],0));
    int ans=0;
    rep(i,1,n)
    {
        if(p[i]>st.top().first)
        {
            st.push(pii(p[i],1));
            ans = max(ans,st.top().second);
        }
        else
        {
            int curmax=0;
            while(!st.empty() && p[i]<=st.top().first)
            {
                curmax = max(curmax,st.top().second);
                ans = max(ans,curmax);
                st.pop();
            }
            if(st.empty())
            {
                st.push(pii(p[i],0));
            }
            else
            {
                st.push(pii(p[i],curmax+1));
                ans = max(ans,st.top().second);
            }
        }

    }
    cout<<ans<<endl;
    return 0;
}

