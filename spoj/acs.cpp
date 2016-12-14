#include <bits/stdc++.h>
using namespace std;
int row[1234],invrow[1234],col[5678],invcol[5678];
int main()
{
    char ch;
    int i,a,b;
    for(i=0;i<1234;i++){row[i]=i;invrow[i]=i;}
    for(i=0;i<5678;i++){col[i]=i;invcol[i]=i;}
    while((ch=getchar())!=EOF)
    {
       if(ch=='R')
       {
           cin>>a>>b;
           a--;b--;
           int temp = row[a];
           row[a]=row[b];
           row[b]=temp;
           invrow[row[a]] = a;
           invrow[row[b]] = b;
       }
       else if(ch=='C')
       {
           cin>>a>>b;
           a--;b--;
           int temp = col[a];
           col[a]=col[b];
           col[b]=temp;
           invcol[col[a]] = a;
           invcol[col[b]] = b;
       }
       else if(ch=='Q')
       {
           cin>>a>>b;
           a--;b--;

           int num = row[a]*5678 + col[b]+1;
           cout<<num<<endl;
       }
       else if(ch=='W')
       {
           cin>>a;
           int r = a/5678 - (a%5678==0);
           int c = a%5678;
           if(c==0)c=5677;
           else c--;
           cout<<invrow[r]+1<<' '<<invcol[c]+1<<endl;
       }

    }
    return 0;
}
