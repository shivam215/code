#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c,step,i,j;
        cin>>a>>b;
        c=0;
        for(i=a;i>=0;i=i/2)
        {
            step=c;
            for(j=2*i;j<=b;j=j*2)
            {
                step++;
                if(j==b)break;
            }
            if(i==b){step=c;break;}
            if(j==b)break;
            c++;
        }
        cout<<step<<endl;
    }
}
