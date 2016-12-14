#include <bits/stdc++.h>
#define scano(x) scanf("%d",&x)
#define scant(x,y) scanf("%d%d",&x,&y)
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int a[100005];
int main()
{
    int t;
    scano(t);
    while(t--)
    {
        int n,m;
        scant(n,m);
        rep(i,0,m)scano(a[i]);
        sort(a,a+m);
        int j=m-1,i=0;
        int res=0;
        while(j>0 && j>i)
        {
            a[i]--;
            if(a[i]==0)i++;
            res++;
            j--;
        }
        printf("%d\n",res);
    }
}
