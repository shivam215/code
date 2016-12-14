#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll a;
    cin>>a;
    ll b = a%6;
    if(b==0||b==1||b==3)cout<<"yes"<<endl;
    else cout<<"no"<<endl;
    return 0;
}
