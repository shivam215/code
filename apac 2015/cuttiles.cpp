#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int sides[100005];
int coun;

void rec(int a, int b)
{
    if (a < b)
    {
        int t = a;
        a = b;
        b = t;
    }
    if (a == 0 || b == 0)
        return;
    int max = log2(b);

    while (max >= 0 && sides[max] == 0)
        max--;
    if (max == -1)
        return;
    sides[max]--;
    coun++;
    int ss = 1 << max;
    rec(b - ss, ss);
    rec(a - ss, b);
}

int solve()
{
    int n,m,temp;
    cin>>n>>m;
    for (int i = 0; i < n; i++)
    {
        cin>>temp;
        sides[temp]++;
    }
    int ans = 0;
    for (; coun < n; ans++)
    {
        rec(m, m);
    }
    coun = 0;
    return ans;

}

int main()
{
    freopen("cutlarge.in","r",stdin);
    freopen("cutlarge.out","w",stdout);
    int t;
    cin>>t;
    rep(test,1,t+1)
    {
        int res = solve();
        printf("Case #%d: %d\n",test,res);
    }
    return 0;
}
