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
int x[250004],y[250004];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        rep(i,0,n)
        {
            rep(j,0,n)
            {
                int temp;
                cin>>temp;
                x[temp] = i;
                y[temp] = j;
            }
        }
        int i=1,res=0;
    while(i<n*n)
    {
        res+=abs(x[i+1]-x[i]) + abs(y[i+1]-y[i]);
        i++;
    }
    cout<<res<<endl;
    }
    return 0;
}