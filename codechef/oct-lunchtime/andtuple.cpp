#include <bits/stdc++.h>
#define mod 1000000009
using namespace std;
long long mem[100][500];
long long n,k,t;
long long solve(long long b, long long carry)
{
    if(b<0)
    {
        if(carry==0)return 1;
        else return 0;
    }
    long long& temp = mem[b][carry];
    if(temp>=0)
        return temp;
    temp=0;
    if(n&(1LL<<b))
        carry++;
    for(int send=0;send<=k-1;send++){
        if(carry-send<=k and send<=carry){
            temp =(temp+solve(b-1,2*send))%mod;
        }
    }
    return temp;
}

int main()
{
    cin>>t;
    while(t--)
    {
        memset(mem,-1,sizeof(mem));
        cin>>k>>n;
        cout<<solve(63LL,0LL)<<endl;
    }
}
