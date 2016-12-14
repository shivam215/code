#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
     *b = temp;
}
int main()
{
    while(1)
    {
        int a,b;
        cin>>a>>b;
        if(a==-1 && b==-1)break;
        if(a>b)swap(&a,&b);

        int quo = b/(a+1);
        int rem = b%(a+1);
        int ans = quo + 1 - (rem==0);
        cout<<ans<<endl;
    }
    return 0;
}
