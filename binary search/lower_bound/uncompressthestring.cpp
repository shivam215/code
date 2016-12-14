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
ll cnt[100005][26],len[100005];
string s;
int bin(ll n)
{
    int low=1,high=s.size()+1;
    while(low<high-1)
    {
        int mid = (low+high)/2;
        if(len[mid]>=n && len[mid-1]<n)return mid;
        else if(len[mid]<n)low=mid+1;
        else high = mid-1;
    }
    if(len[low]>=n)return low;
    else return high;
}
ll solve(ll n,char ch)
{
    if(n==0)return 0;
    int in = bin(n);
    if(s[in-1]>='a'&&s[in-1]<='z')
    {
        return cnt[in][ch-'a'];
    }
    else
    {
        ll quo = n/len[in-1];
        ll rem = n%(len[in-1]);
        return quo*cnt[in-1][ch-'a'] + solve(rem,ch);
    }
}
int main()
{
    int q;
    cin>>s>>q;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            for(int j=0;j<26;j++)
            {
                cnt[i+1][j] = (s[i]-'0')*cnt[i][j];
            }
            len[i+1] = (s[i]-'0')*len[i];
        }
        else
        {
            for(int j=0;j<26;j++)
            {
                cnt[i+1][j] = cnt[i][j];
            }
            cnt[i+1][s[i]-'a']++;
            len[i+1] = len[i]+1;
        }
    }
    while(q--)
    {
        ll l,r;
        char x;
        cin>>x>>l>>r;
        ll res = solve(r,x) - solve(l-1,x);
        cout<<res<<endl;
    }
    return 0;
}
