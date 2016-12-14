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
int ismor(ll n1, ll n2)
{
    int flag=1;
    while(n1>0 && n2>0)
    {
        int a = (n1%10);
        int b = (n2%10);
        if(a!=b)
        {
            flag=0;break;
        }
        n1/=10;n2/=10;
    }
    if(flag)return 1;
    else return 0;
}
int main()
{
    int n,q,a[10003];
    scant(n,q);
    for(int i=0;i<n;i++)
    {
        ll temp;
        cin>>temp;
        if(ismor(temp,temp*temp)==1)a[i]=1;
        else a[i]=0;
    }
    while(q--)
    {
        ll f,g,h;
        cin>>f>>g>>h;
        if(f==2)
        {
            int cnt=0;
            for(int i=g;i<=h;i++)
            {
                if(a[i]==1)cnt++;
            }
            printf("Automorphic: %d\n",cnt);
        }
        else if(f==1)
        {
            int cnt=0;
            for(int i=g;i<=h;i++)
            {
                if(a[i]==0)cnt++;
            }
            printf("Non Automorphic: %d\n",cnt);
        }
        else
        {
            if(ismor(h,h*h))a[g]=1;
            else a[g]=0;
        }
    }
    return 0;

}
