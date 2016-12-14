#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);cin.tie(0);
long long int findmin(int p, int q, int r, int s);
using namespace std;
int main()
{
    int t,n1,n2,n3;
    long long result;
    cin>>t;
    while(t--)
    {
       cin>>n1>>n2>>n3;
    if(n1==0 && n2==0 && n3==0)
        result = 1;
    else
        result = ((n1>0)?findmin(n1-1,n2,n3,0):0)+((n2>0)?findmin(n1,n2-1,n3,1):0)+((n3>0)?findmin(n1,n2,n3-1,2):0);

    cout<<result<<endl;}
    return(0);
}
long long findmin(int p, int q, int r, int s)
{
    if(p==0 && q==0 && r==0)
        return 1;
    else if(s==0 && p>0 && q==0 && r==0)
        return 0;
    else if(s==1 && p==0 && q>0 && r==0)
        return 0;
    else if(s==2 && p==0 && q==0 && r>0)
        return 0;
    static long long a[16][16][16][3];
    long long x;

    if(a[p][q][r][s])
        return a[p][q][r][s];
    if(s==0)
        x = ((q>0)?findmin(p,q-1,r,1):0) + ((r>0)?findmin(p,q,r-1,2):0);
    else if(s==1)
        x = ((p>0)?findmin(p-1,q,r,0):0) + ((r>0)?findmin(p,q,r-1,2):0);
    else
        x = ((q>0)?findmin(p,q-1,r,1):0) + ((p>0)?findmin(p-1,q,r,0):0);

    return a[p][q][r][s] = x;

}

