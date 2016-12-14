#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,temp;
    vector<int> vec;
    cin>>t;
    while(t--)
    {
        vec.clear();
        cin>>n;
        if(n&1){cout<<n<<endl;continue;}
        temp = n;
        while(temp>0)
        {
            int a = temp%2;
            vec.push_back(a);
            temp = temp/2;
        }
        int len = vec.size()-1;
        int res=0;
        for(int i=0;i<vec.size();i++)
        {
            res = res + vec[i]*(1<<len);
            len--;
        }
        cout<<res<<endl;
    }
    return 0;
}
