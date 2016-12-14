#include <bits/stdc++.h>
#define ll long long
using namespace std;
map<int,int> pi;
ll palin[100005];
bool prime[100007];
void sieve()
{
    for(int i=1;i<=100000;i++)prime[i]=1;
    for(int i=2;i*i<=100000;i++)
    {
        if(prime[i]==1)
        {
            for(int j=i*i;j<=100000;j+=i)
            {
                prime[j]=0;
            }
        }
    }
}
int ispalin(int n)
{
    string s;
    while(n>0)
    {
        s = s + (char)(n%10+'0');
        n = n/10;
    }
    string s1 = s;
    reverse(s.begin(),s.end());
    return (s1==s);

}
int main()
{
    int p,q;
    cin>>p>>q;
    sieve();
    palin[1]=1;
    for(int i=2;i<=100005;i++)
    {
        palin[i] = palin[i-1]+ispalin(i);
    }
    pi[1]=0;
    pi[2]=1;
    for(int i=3;i<100005;i++)
    {
        pi[i] = pi[i-1] + (prime[i]==1);
    }
    int low=1,high=100;
    while(low<high)
    {
        int mid = (low+high)/2;
        if(q*pi[mid]>p*palin[mid])
        {
            high = mid-1;
        }
        else
        {
            low = mid;
        }
    }
    cout<<low<<endl;
    return 0;
}
