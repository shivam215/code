#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,res,res1,i,j,coun;
    string s,s1,s2;
    int a[26],b[26];
    cin>>n>>s;

    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    for(i=0;i<n/2;i++) a[s[i]-'a']++;
    for(i=n/2;i<n;i++) b[s[i]-'a']++;

    i=25;j=25;
    coun=1;res1=0;
    while(coun<=n/2 && i>=0 && j>=0)
    {
        if(i==j)
        {
            res1 = res1 + b[j];
            coun = coun+b[j];
            //b[0]=b[0]+b[j];
            j--;
        }
        else
        {
            if(a[i]==b[j])
            {
                coun = coun+b[j];
                i--;j--;
            }
            else if(a[i]>b[j])
            {
                coun = coun + b[j];
                a[i] = a[i] - b[j];
                j--;
            }
            else
            {
                coun = coun + a[i];
                b[j] = b[j] - a[i];
                i--;
            }

        }
    }
    res=res1;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    for(i=0;i<n/2;i++) b[s[i]-'a']++;
    for(i=n/2;i<n;i++) a[s[i]-'a']++;

    i=25;j=25;
    coun=1;res1=0;
    while(coun<=n/2 && i>=0 && j>=0)
    {
        if(i==j)
        {
            res1 = res1 + b[j];
            //b[0] = b[0]+b[j];
            coun = coun+b[j];
            j--;
        }
        else
        {
            if(a[i]==b[j])
            {
                coun = coun+b[j];
                i--;j--;
            }
            else if(a[i]>b[j])
            {
                coun = coun + b[j];
                a[i] = a[i] - b[j];
                j--;
            }
            else
            {
                coun = coun + a[i];
                b[j] = b[j] - a[i];
                i--;
            }

        }
    }
    res = min(res,res1);

    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));

    for(i=0;i<n/2;i++) a[s[i]-'a']++;
    for(i=n/2;i<n;i++) b[s[i]-'a']++;
    res1=0;

    for(i=0;i<26;i++)
    {
        res1 = res1 + (a[i]-b[i])*(a[i]>b[i]);
    }
    res = min(res,res1);
    cout<<res<<endl;
    return 0;
}
