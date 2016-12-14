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
int main()
{
    int n,t;
    cin>>n>>t;
    string s1,s2;
    cin>>s1>>s2;
    int a=0,b=0;
    rep(i,0,n)
    {
        if(s1[i]==s2[i])b++;
        else a++;
    }
    int diff = n-t;
    if(b>=diff)
    {
        string str;
        rep(i,0,n)
        {
            if(s1[i]==s2[i])
            {
                if(diff>0)
                {
                    str = str + s1[i];
                    diff--;
                }
                else
                {
                    if(s1[i]=='a')str = str + 'b';
                    else str = str + 'a';
                }
            }
            else
            {
                rep(j,0,26)
                {
                    if(s1[i]-'a'==j||s2[i]-'a'==j)continue;
                    str = str + (char)(j+'a');
                    break;
                }
            }
        }
        cout<<str<<endl;
    }
    else
    {
        if((a/2)>=(diff-b))
        {
            int temp = 2*(diff-b);
            int flag=1;
            string str;
            rep(i,0,n)
            {
                if(s1[i]==s2[i])
                {
                    str = str + s1[i];
                }
                else
                {
                    if(temp>0)
                    {
                        if(flag)str = str + s1[i];
                        else str = str + s2[i];
                        flag=1-flag;
                        temp--;
                    }
                    else
                    {
                        rep(j,0,26)
                        {
                            if(s1[i]-'a'==j||s2[i]-'a'==j)continue;
                            str = str + (char)(j+'a');
                            break;
                        }
                    }
                }
            }
            cout<<str<<endl;

        }
        else
        {
            cout<<-1<<endl;
        }
    }
    return 0;
}
