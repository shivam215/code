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
string s;
int ind,n;
int height()
{
    if(ind==n)return 0;
    int temp = ind;
    ind++;
    if(s[temp]=='n')
    {
        return max(height(),height())+1;
    }
    else return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>s;
        n = s.size();
        ind=0;
        cout<<height()<<endl;
    }
    return 0;
}
