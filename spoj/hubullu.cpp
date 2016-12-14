#include <bits/stdc++.h>
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
    cin>>t;
    while(t--)
    {
        int n,type;
        cin>>n>>type;
        if(type==0)
        {
            cout<<"Airborne wins."<<endl;
        }
        else
        {
            cout<<"Pagfloyd wins."<<endl;
        }
    }
    return 0;
}
