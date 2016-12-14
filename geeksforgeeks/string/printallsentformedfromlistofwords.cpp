#include <bits/stdc++.h>
using namespace std;
string str[3][3] = {{"you", "we"},{"have", "are"},{"sleep", "eat", "drink"}};
void print(string s,int i)
{
    if(i==3)
    {
        cout<<s<<endl;
        return;
    }
    for(int j=0;j<3;j++)
    {
        if(str[i][j]!="")
        {
            if(s=="")print(s+str[i][j],i+1);
            else print(s+' '+str[i][j],i+1);
        }
    }
}
int main()
{

    print("",0);
    return 0;

}
