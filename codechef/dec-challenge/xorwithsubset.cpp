#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);cin.tie(0);
using namespace std;
int findoptimal(int* a, int N, int K)
{
    if(N==0)
        return K;
    int res = findoptimal(a,N-1,K);
    cout<<res<<endl;
    return(max(res,(res^a[N-1])));

}
int main()
{
    int T,N,K,temp,i,j;
    int a[10000];
    cin>>T;
    for(i=1;i<=T;i++)
    {
        cin>>N;
        cin>>K;
        for(j=0;j<N;j++)
        {
           cin>>a[j];
        }
        cout<<findoptimal(a,N,K);


    }
}
