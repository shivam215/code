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
int a[50][50];
int main()
{

    int t;
    cin>>t;
    rep(test,1,t+1)
    {
        int n,i,j,k;
        string s;
        cin>>n>>s;
        for(i=0; i<n; i++)for(j=0; j<n; j++)
            {
                if(s=="right")cin>>a[i][n-1-j];
                else if(s=="left")cin>>a[i][j];
                else if(s=="up")cin>>a[j][i];
                else cin>>a[j][n-1-i];
            }
        for(i=0; i<n; i++)
        {
            k=0;
            for(j=0; j<n; j++)
            {
                if(a[i][j]!=0)
                {
                    a[i][k] = a[i][j];
                    k++;
                }
            }
            for(; k<n; k++)a[i][k]=0;
        }
        for(i=0; i<n; i++)
        {
            for(j=0; j<n-1; j++)
            {
                if(a[i][j]==a[i][j+1])
                {
                    a[i][j] = 2*a[i][j];
                    a[i][j+1]=0;
                }
            }
        }
        for(i=0; i<n; i++)
        {
            k=0;
            for(j=0; j<n; j++)
            {
                if(a[i][j]!=0)
                {
                    a[i][k] = a[i][j];
                    k++;
                }
            }
            for(; k<n; k++)a[i][k]=0;
        }
        printf("Case #%d:\n",test);
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                if(s=="right")cout<<a[i][n-1-j]<<' ';
                else if(s=="left")cout<<a[i][j]<<' ';
                else if(s=="up")cout<<a[j][i]<<' ';
                else cout<<a[j][n-1-i]<<' ';
            }
            cout<<endl;
        }



    }
    return 0;
}
