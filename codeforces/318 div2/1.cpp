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
priority_queue<int > pq;
int main()
{
    int n,x;
    cin>>n>>x;
    int y;
    rep(i,1,n)
    {
        cin>>y;
        pq.push(y);
    }

    if(x>pq.top())
    {
        cout<<"0\n";
        return 0;
    }
    int t1,t2;
    int fa=0;
    while(true)
    {
        t1=pq.top();
        pq.pop();
        if(x>t1)
        {
            cout<<fa<<"\n";
            return 0;
        }

        x=x+1;
        t1=t1-1;
        fa++;
       // cout<<x<<" "<<t1<<" "<<fa<<"\n";
        pq.push(t1);
    }

    return 0;
}
