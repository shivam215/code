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
int a[1000006],le[1000006],ri[1000006];
pair<int,ll> cnt[1000006];
char str[1000006];
int n;
char opp(char c)
{
    if(c=='D')return 'C';
    else return 'D';
}
int bin(int k)
{
    int low=0,high=n-1;
    while(low<high-1)
    {
        int mid = (low+high)/2;
        if(cnt[mid].first<=k && cnt[mid+1].first>k)return mid;
        else if(cnt[mid].first>k)high = mid-1;
        else low = mid+1;
    }
    if(cnt[low].first<=k && cnt[high].first<=k)return high;
    else if(cnt[low].first<=k)return low;
    else return -1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int q;
    cin>>n>>q;
    rep(i,0,n)cin>>a[i];
    stack< pii > st;
    st.push(pii(a[0],0));
    for(int i=1;i<n;i++)
    {
        if(a[i]<=st.top().first)st.push(pii(a[i],i));
        else
        {
            while(!st.empty() &&a[i]>st.top().first)
            {
                ri[(st.top()).second] = i;
                st.pop();
            }
            st.push(pii(a[i],i));
        }
    }
    while(!st.empty())
    {
        ri[st.top().second]=-1;
        st.pop();
    }
    st.push(pii(a[n-1],n-1));
    for(int i=n-2;i>=0;i--)
    {
        if(a[i]<st.top().first)st.push(pii(a[i],i));
        else
        {
            while(!st.empty() &&a[i]>=st.top().first)
            {
                le[st.top().second] = i;
                st.pop();
            }
            st.push(pii(a[i],i));
        }
    }
    while(!st.empty())
    {
        le[st.top().second]=-1;
        st.pop();
    }
    for(int i=0;i<n;i++)
    {
        int l,r;
        l = (le[i]!=-1)?i-le[i]-1:i;
        r = (ri[i]!=-1)?ri[i]-i-1:n-1-i;
        cnt[i].first = a[i];
        cnt[i].second =  l + r + l*r + 1;
    }
    sort(cnt,cnt+n);
    for(int i=1;i<n;i++)
    {
        cnt[i].second += cnt[i-1].second;
    }
    int p=0;
    while(q--)
    {
        char ch,d;
        int k;
        cin>>ch>>k>>d;
        if(ch=='>')
        {
            int in = bin(k);
            ll res = (n*(n+1))/2;
            if(in!=-1)res = res - cnt[in].second;
            if(res&1)str[p]=d;
            else str[p]=opp(d);
        }
        else if(ch=='<')
        {
            int in = bin(k-1);
            ll res=0;
            if(in!=-1)res = cnt[in].second;
            if(res&1)str[p]=d;
            else str[p]=opp(d);
        }
        else
        {
            ll res=0;
            int in1 = bin(k);
            int in2 = bin(k-1);
            if(in1!=-1)res = cnt[in1].second;
            if(in2!=-1)res -= cnt[in2].second;
            if(res&1)str[p]=d;
            else str[p]=opp(d);
        }
        p++;
    }
    str[p]='\0';
    printf("%s\n",str);
    return 0;
}
