#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int main()
{   string s1,s2;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>s1>>s2;
        sort(s2.begin(),s2.end());
        int p=0;
        rep(i,0,s1.size())
        {
            if(p<s2.size()&&s1[i]>s2[p])
            {
                s1[i]=s2[p];
                p++;
            }
        }
        cout<<s1<<"\n";
    }
    return 0;
}
