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
int a[100][100],f[100];
int main()
{
    int t;
    scano(t);
    while(t--)
    {
        int n,m;
        scant(n,m);
        int res=0;
        rep(i,0,n)rep(j,0,m)scano(a[i][j]);
        rep(i,0,n)
        {
            int cur = a[i][m-1];
            for(int j=m-2;j>=0;j--)
            {
                if(a[i][j]>cur)cur=a[i][j];
                else cur = a[i][j]-1;
            }
            res = res^cur;
        }
        if(res==0)printf("SECOND\n");
        else printf("FIRST\n");
    }
    return 0;
}

