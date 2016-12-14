#include <bits/stdc++.h>
using namespace std;
void swapp(char* a, char* b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t,n;
    int a[100005];
    string s;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cin>>s;
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)
        {
            swapp(&s[i],&s[a[i]-1]);
        }
        for(int i=0;i<s.size();i++)cout<<s[i];
        cout<<endl;
    }
    return 0;
}
