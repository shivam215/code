#include <iostream>
int getting(int x, int y);
using namespace std;
int main()
{
    int t,i,m,result;
    cin >> t;
    for(i=1;i<=t;i++)
    {
        cin >> m;
        result = getting(m,m);
        cout << result << endl;
    }
    return(0);
}
int getting(int x, int y)
{
    if(x==1 || y==1)
        return(x+y);
    static int temp[15][15];
    int res;
    if(temp[x][y])
        return temp[x][y];
    res = getting(x-1,y)+ getting(x,y-1);
    return(temp[x][y] = res);


}
