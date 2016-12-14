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
int main()
{
    string s;
    int test=1;
    while(cin>>s)
    {
        int cnt=0;
        int flag=0;
        for(int i=s.size()-1;i>=0;)
        {
            if(s[i]=='0')
            {
                flag=1;
                i--;
                continue;
            }
            while(i>=0 && s[i]=='1')
            {
                i--;
            }
            if(flag)cnt+=2;
            else
            {
                cnt++;flag=1;
            }

        }
        printf("Game #%d: %d\n",test,cnt);
        test++;
    }
}
