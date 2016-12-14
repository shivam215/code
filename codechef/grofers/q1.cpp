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
    string str3,str2,str1;
    int temp;
    char ch;
    getline(cin,str3);
    cin>>str2;
    str1=str2;

    int a=str2.length();
    int b=a;
    while(a<str3.length())
    {
        str2=str2+str1;
        a=a+b;
    }
    int n=str3.length();
    for(int i=0; i<n; i++)
    {
        if(str3[i]>='a'&&str3[i]<='z' )
        {
            if(str2[i]>='a')
            {

                temp=(int)(str2[i]-'a');
                if(-temp+str3[i]<'a')
                    ch=char(-temp+str3[i]+26);
                else ch=char(-temp+str3[i]);
                str3[i]=ch;
            }
            else
            {
                temp=(int)(str2[i]-'A');
                if(str3[i]-temp<'a')
                    ch=char(-temp+str3[i]+26);
                else ch=char(-temp+str3[i]);
                str3[i]=ch;
            }
        }

        if(str3[i]>='A'&&str3[i]<='Z' )
        {
            if(str2[i]>='a')
            {

                temp=(int)(str2[i]-'a');
                if(-temp+str3[i]<'A')ch=char(-temp+str3[i]+26);
                else ch=char(-temp+str3[i]);
                str3[i]=ch;
            }
            else
            {
                temp=(int)(str2[i]-'A');

                if(str3[i]-temp<'A')ch=char(-temp+str3[i]+26);
                else ch=char(-temp+str3[i]);

                str3[i]=ch;
            }
        }

    }
    cout<<str3<<endl;
    return 0;
}
