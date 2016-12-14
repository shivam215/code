#include <bits/stdc++.h>
#define MAX 100005
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
int a[100];
int main()
{
    int t;
    scano(t);
    while(t--)
    {
        int p,l;
        scant(p,l);
        rep(i,0,l)scano(a[i]);
        int low=0,high=10000000;
        while(low<high)
        {
            int mid = (low+high)/2;
            int cnt=0;
            rep(i,0,l)
            {
                int temp = sqrt(1+(8*mid)/a[i]);
                cnt = cnt + (temp-1)/2;
            }
            if(cnt<p)
            {
                low = mid+1;
            }
            else if(cnt>=p)
            {
                high = mid;
            }
        }
        cout<<high<<endl;
    }
    return 0;
}

