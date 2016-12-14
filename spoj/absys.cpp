#include <bits/stdc++.h>
#define inf 1000000000
#define mod 1000000007
#define scano(x) scanf("%d",&x)
#define scanll(x) scanf("%lld",&x)
#define scant(x,y) scanf("%d%d",&x,&y)
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector< pii >
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fe first
#define se second
using namespace std;
int convert(string s)
{
    int res=0;
    for(int i=0;i<s.size();i++)
    {
        res = res*10 + s[i]-'0';
    }
    return res;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s1,s2,s3,s4,s5;
        cin>>s1>>s2>>s3>>s4>>s5;
        int flag=1;
        for(int i=0;i<s5.size();i++)
        {
            if(s5[i]=='m')
            {
                flag=0;break;
            }
        }
        if(flag==0)
        {
            int a = convert(s1);
            int b = convert(s3);
            int c = a+b;
            printf("%d + %d = %d\n",a,b,c);
            continue;
        }
        flag=1;
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]=='m')
            {
                flag=0;break;
            }
        }
        if(flag==0)
        {
            int c = convert(s5);
            int b = convert(s3);
            int a = c-b;
            printf("%d + %d = %d\n",a,b,c);
            continue;
        }
        int c = convert(s5);
        int a = convert(s1);
        int b = c-a;
        printf("%d + %d = %d\n",a,b,c);
    }
    return 0;
}
