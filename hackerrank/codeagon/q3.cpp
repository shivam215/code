#include <bits/stdc++.h>
#define B 320
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int a[100005],b[330],c[330][100005];
int main()
{
    ios_base::sync_with_stdio(false);
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        b[i/B] = max(b[i/B],a[i]);
        c[i/B][a[i]]++;
    }
    while(q--)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        l--;r--;
        int p = l/B;
        int q = r/B;
        int mx=0;
        if(p==q)
        {
            for(int i=l;i<=r;i++)
            {
                mx = max(mx,a[i]);
            }
        }
        else
        {
            for(int i=l;i<=(p+1)*B-1;i++)
            {
                mx = max(mx,a[i]);
            }
            for(int i=p+1;i<q;i++)
            {
                mx = max(mx,b[i]);
            }
            for(int i=q*B;i<=r;i++)
            {
                mx = max(mx,a[i]);
            }
        }
        int cnt=0;
        if(p==q)
        {
            for(int i=l;i<=r;i++)
            {
                if(a[i]==mx)cnt++;
            }
        }
        else
        {
            for(int i=l;i<=(p+1)*B-1;i++)
            {
                if(a[i]==mx)cnt++;
            }
            for(int i=p+1;i<q;i++)
            {
                cnt = cnt + c[i][mx];
            }
            for(int i=q*B;i<=r;i++)
            {
                if(a[i]==mx)cnt++;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
