#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<long long int> vec(100000);
    long long int result;
    int T,n,i,Q,a,b,j;
    cin >> T;
    for(i=1;i<=T;i++)
    {
        cin>>n;
        for(j=0;j<n;j++)
        {
            cin>>vec[j];
        }
        for(j=1;j<n;j++)
        {
            vec[j] = vec[j] + vec[j-1];
        }
        cin>>Q;
        for(j=1;j<=Q;j++)
        {
            cin>>a>>b;
            result = vec[b] - vec[a];
            cout<<result<<endl;
        }

    }
    return(0);
}
