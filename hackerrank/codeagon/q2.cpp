#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int n;
map<string,int> m;
string s;
void solve(int i, string output,stack<char> st)
{
    if(output.size()==n)
    {
        m[output]++;
        return ;
    }
    stack<char> temp = st;
    string otemp = output;
    if(!st.empty())
    {
        char c = st.top();
        st.pop();
        output = output + c;
        solve(i,output,st);
    }
    if(i<n)
    {
        temp.push(s[i]);
        solve(i+1,otemp,temp);
    }
}
int main()
{
    cin>>s;
    n = s.size();
    stack<char> st;
    solve(0,"",st);
    map<string,int>::iterator it;
    int cnt=0;
    for(it=m.begin();it!=m.end();it++)
    {
        //cout<<it->first<<' '<<it->second<<endl;
        if(it->second>0)
        {
            cnt++;
        }
    }
    cout<<m[s]<<' '<<cnt<<endl;
    return 0;

}
