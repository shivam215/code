#include <bits/stdc++.h>
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
int main()
{
    int t;
    char c;
    set<string> se;
    string s;
    cin>>t;
    c = getchar();
    while(t--)
    {
        se.clear();
        while((c=getchar())!='\n')
        {
            if(c==' ')
            {
                if(!s.empty())se.insert(s);
                s.clear();
            }
            else
            {
                s = s + c;
            }
        }
        if(!s.empty())se.insert(s);
        s.clear();
        printf("%d\n",se.size());

    }
    return 0;
}
