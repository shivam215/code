#include <iostream>
using namespace std;
int main()
{
    int n,i,coun=0;
    long long int t;
    cin >> n;
    for(i=1;i<=n;i++)
    {
        cin >> t;
        if(!(t%3))
            coun++;
    }
    cout << coun;
    return(0);
}

