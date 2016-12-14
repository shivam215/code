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
int a[100005],pos[100005];
int main()
{
    while(1)
    {
        int n;
        cin>>n;
        if(n==0)break;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            pos[a[i]]=i+1;
        }
        int flag=1;
        for(int i=0;i<n;i++)
        {
            if(a[i]!=pos[i+1])
            {
                flag=0;
                break;
            }
        }
        if(flag)cout<<"ambiguous"<<endl;
        else cout<<"not ambiguous"<<endl;
    }
    return 0;
}
