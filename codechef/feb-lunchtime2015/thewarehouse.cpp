#include <bits/stdc++.h>
using namespace std;
string s;
int solve(char x, char y, char z)
{
    int a=0,res=0,b=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==y || s[i]==z)a++;
        if(s[i]==z)b++;
        if(s[i]==x)res+=a;
        if(s[i]==y)res+=b;
    }
    return res;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>s;
        int a[6];
        a[0]=solve('r','g','b');
        a[1]=solve('r','b','g');
        a[2]=solve('g','r','b');
        a[3]=solve('g','b','r');
        a[4]=solve('b','r','g');
        a[5]=solve('b','g','r');
        int mn=a[0];
        for(int i=1;i<=5;i++)if(a[i]<mn)mn=a[i];
        cout<<mn<<endl;

    }
    return 0;
}
