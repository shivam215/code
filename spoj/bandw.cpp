#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a,b;
    while(1)
    {
        cin>>a>>b;
        if(a[0]=='*'&&b[0]=='*')break;
        int n = a.size();
        int res=0;
        for(int i=0;i<n;i++)
        {
            while(i<n && a[i]==b[i])i++;
            if(i<n && a[i]!=b[i])
            {
                res++;
                while(i<n && a[i]!=b[i])i++;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
