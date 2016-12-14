#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);cin.tie(0);
using namespace std;
int makenumber(char* a, int length)
{
    int j=0,x=1,num=0;
    for(j=0;j<=length;j++)
    {
        num = num + (a[j]-'0')*x;
        x = x*10;
    }
    return num;
}
int main()
{
    int i=0,l,j,n;
    char a[20];
    cin>>a;
    l = strlen(a);
    n = makenumber(a,l-1);
    while(a[i]!='\0')
    {
        if(a[i]!='9')
            break;
        if(a[i]=='9' && i==l-1)
        {
            cout<<n+2;
            return(0);
        }
        i++;

    }
    for(i=0,j=l-1;i<j;i++,j--)
    {
        a[j] = a[i];
    }
    if(makenumber(a,l-1)>n)
    {
        cout<<makenumber(a,l-1);
        return(0);
    }
    if(i==j)
    {
        if(a[i]!='9')
            a[i] = a[i] + 1;
        else
        {
            while(i>=0&&j<=l-1)
            {
                if(a[i]=='9')
                {
                    a[i] = '0';
                    a[j] = '0';
                }
                else
                {
                    a[i] = a[i]+1;
                    a[j] = a[j]+1;
                    break;
                }
                i--;
                j++;
            }
        }
    }
    else
    {
        i--;
        j++;
        while(i>=0&&j<=l-1)
        {
            if(a[i]!='9')
            {
                a[i] = a[i] + 1;
                a[j] = a[j] + 1;
                break;
            }
            else
            {
                a[i] = '0';
                a[j] = '0';
            }
            i--;
            j++;
        }
    }
    cout<<makenumber(a,l-1);
    return(0);

}

