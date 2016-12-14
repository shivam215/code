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
    ll i,j,n,carry,sum;
    cin>>t;
    vector<ll> vec,v;
    while(t--)
    {
        cin>>n;
        vec.clear();
        v.clear();
        v.push_back(1);
        for(i=2;i<=n;i++)
        {
            vec = v;
            v.clear();
            carry=0;
            for(j=0;j<vec.size();j++)
            {
                sum = i*vec[j]+carry;
                carry = sum/10;
                v.push_back(sum%10);
            }
            while(carry>0)
            {
                v.push_back(carry%10);
                carry = carry/10;
            }
        }
        for(i=v.size()-1;i>=0;i--)
        {
            cout<<v[i];
        }
        cout<<endl;
    }
    return 0;
}
