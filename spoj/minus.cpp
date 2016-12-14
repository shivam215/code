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
map<pii,int> ma;
int a[102],op[102];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int sum=0;
        for(int i=0;i<n;i++){cin>>a[i];sum+=a[i];}
        if(n == 1) printf("\n");
        else if(n == 2) printf("1\n");
        else
        {
            ma.clear();
        ma[mp(0,a[0])]=1;
        for(int i=1;i<n;i++)
        {
            for(int j=-sum;j<=sum;j++)
            {
                ma[mp(i,j)] = ma[mp(i-1,j-a[i])] | ma[mp(i-1,j+a[i])];
            }
        }
        int j = n-1;
        int k = m;
        //cout<<ma[mp(n-2,9)]<<endl;
        while(j!=0)
        {
            if(ma[mp(j-1,k-a[j])]==1)
            {
                op[j] = 1;
                k = k-a[j];
            }
            else if(ma[mp(j-1,k+a[j])]==1)
            {
                op[j]=2;
                k = k + a[j];
            }
            j--;
        }
        for(int i = n - 1,cont = 0;i >= 1;--i){
                if(op[i] == 1) ++cont;
                else{
                    for(int j = 0;j < cont;++j)
                        printf("%d\n",i + 1);

                    n -= cont;
                    cont = 0;
                }
            }

            for(int i = 1;i < n;++i)
                printf("1\n");

        }
        printf("\n");

    }
    return 0;
}
