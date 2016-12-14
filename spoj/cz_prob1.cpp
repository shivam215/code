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
int prime[100005];
void sieve()
{
    rep(i,2,100005)prime[i]=1;
    for(int i=2;i*i<100005;i++)
    {
        if(prime[i])
        {
            for(int j=i*i;j<100005;j+=i)
            {
                prime[j]=0;
            }
        }
    }
}
int main()
{
    int t;
    cin>>t;
    sieve();
    set<int> s;
    set<int>::iterator it;
    for(int i=0;i<=8000;i++)
    {
        for(int j=0;(j*j+i*i)<=8000;j++)
        {
            if(i*i+j*j<=8000&&prime[i*i+j*j])
            {
                s.insert(i*i+j*j);
            }
        }
    }
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        it=s.begin();
        int temp=1;
        while(temp<n)
        {
            it++;
            temp++;
        }
        cout<<*it<<endl;
    }
}
