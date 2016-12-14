#include <bits/stdc++.h>
using namespace std;
int prefix[100];
string s,text;
void compute_lcp()
{
    prefix[0] = 0;
    for(int i=1; i<s.size(); i++)
    {
        int j = prefix[i-1];
        while(j>0 && s[i]!=s[j])
            j = prefix[j-1];
        if(s[i] == s[j]) j+=1;
        prefix[i] = j;
    }
}
void kmp()
{
    int i=0,j=0;
    int n = text.size(),m=s.size();
    while(i<n)
    {
        if(text[i]==s[j])
        {
            i++;j++;
        }
        else
        {
            if(j)j=prefix[j-1];
            else i++;
        }
        if(j==m)
        {
            printf("pattern found at %d\n",i-j);
        }
    }
}
int main()
{
    cin>>text>>s;
    compute_lcp();
    kmp();
    return 0;
}
