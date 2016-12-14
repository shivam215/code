#include <bits/stdc++.h>
using namespace std;
int fac1[1000006],fac2[1000006];
int main()
{
    int a,b,i,coun,res;
    cin>>a>>b;
    int test=1;
    while(a!=0 && b!=0)
    {
        memset(fac1,0,sizeof(fac1));
        memset(fac2,0,sizeof(fac2));
        while(a%2==0)
        {
            fac1[2]++;
            a = a/2;
        }
        for(i=3;i*i<=a;i+=2)
        {
                while(a%i==0){fac1[i]++;a=a/i;}
        }
        if(a>1)fac1[a]++;
        while(b%2==0)
        {
            fac2[2]++;
            b = b/2;
        }
        for(i=3;i*i<=b;i+=2)
        {
                while(b%i==0){fac2[i]++;b=b/i;}
        }
        if(b>1)fac2[b]++;
        //for(i=1;i<12;i++)cout<<fac1[i]<<' '<<fac2[i]<<endl;
        coun=0;res=0;

        for(i=2;i<=1000000;i++)
        {
            if(fac1[i] || fac2[i])
            {
                coun++;
                res += abs(fac1[i]-fac2[i]);
            }
        }
        cout<<test<<". "<<coun<<":"<<res<<endl;
        test++;
        cin>>a>>b;

    }
}
