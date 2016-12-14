#include <bits/stdc++.h>
#define inf 1000000000
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
vector<int> v;
int a[100005];
int bin(int n)
{
    int low=0;
    int high = v.size()-1;
    while(low<high)
    {
        int mid = (low+high)/2;
        if(v[mid]<=n)low=mid+1;
        else if(v[mid]>n)high=mid;
    }
    if(v[high]>n)return high;
    else return -1;
}
int main()
{
    int t;
    scano(t);
    while(t--)
    {
        int n;
        scano(n);
        for(int i=0;i<n;i++)scano(a[i]);
        v.clear();
        for(int i=0;i<n;i++)
        {
            if(v.size()==0)v.pb(a[i]);
            else
            {
                int in = bin(a[i]);
                if(in==-1)v.pb(a[i]);
                else v[in]=a[i];
            }
        }
        printf("%d ",v.size());
        for(int i=0;i<v.size();i++)
        {
            printf("%d ",v[i]);
        }
        printf("\n");
    }
}
