#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);cin.tie(0);
#include <vector>
using namespace std;
int main()
{
    int T,a[1001],b[1025],max,N,K,i,temp,j;
    vector<int> vec;
    cin>>T;
    while(T--)
    {
        cin>>N>>K;
        for(i=0;i<N;i++)
        {
            cin>>a[i];
        }
        b[0]=1;
        for(i=1;i<=1025;i++)
        {
            b[i]=0;
        }
        vec.clear();
        vec.push_back(0);
        for(i=0;i<N;i++)
        {
            for(j=0;j<vec.size();j++)
            {
                temp = (a[i]^vec[j]);
                if(b[temp]==0)
                {
                    vec.push_back(temp);
                    b[temp]=1;
                }
            }
        }
        max = K;
        for(vector<int>::iterator it=vec.begin();it!=vec.end();++it)
        {
            if((K^(*it))>max)
                max = K^(*it);
        }
        cout<<max<<endl;
    }
    return(0);
}
