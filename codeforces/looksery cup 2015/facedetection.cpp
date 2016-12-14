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
    int n,m;
    string s[100];
    string tar = "acef";
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
    }
    int cnt=0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<m-1;j++)
        {
            string str;
            str = str + s[i][j]+s[i][j+1]+s[i+1][j]+s[i+1][j+1];
            sort(str.begin(),str.end());
            if(str==tar)cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;

}
