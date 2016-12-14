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
int arr[1003];
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
        for(int i=0;i<n;i++)cin>>arr[i];
        if(n==1||n==2)
        {
            printf("Case #%d: %d\n",test,n);
            continue;
        }
        stack<int> s;
        while(!s.empty())s.pop();
        s.push(arr[0]);
        s.push(arr[1]);
        for(int i=2;i<n;i++)
        {
            if(s.size()==0||s.size()==1)s.push(arr[i]);
            else
            {
                int a = arr[i];
                int b = s.top();
                s.pop();
                int c = s.top();
                s.pop();
                if((a-b)==k && (b-c)==k)
                {
                    continue;
                }
                else
                {
                    s.push(c);s.push(b);s.push(a);
                }
            }
        }
        int ans = s.size();
        printf("Case #%d: %d\n",test,ans);
    }
    return 0;
}
