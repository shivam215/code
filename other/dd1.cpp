#include <iostream>
#include <climits>
using namespace std;


int min_squares(int n, int m) {
    if (n == m)
        return 1;

    static int cache[100][100]; // Automatically initialized to 0 since static

    if (n < m)
        swap(n, m);
    if (cache[n][m])
        return cache[n][m];

    int x = INT_MAX;

    for (int i = 1; i+i <= n; ++i)
        x = min(x, min_squares(m,i) + min_squares(m, n-i));

    for (int i = 1; i+i <= m; ++i)
        x = min(x, min_squares(i, n) + min_squares(m-i, n));

    return cache[n][m] = x;
}


int main() {
    int T,j,n,m;
    cin>>T;
    for(j=1;j<=T;j++)
    {
      cin>>n;
      cin>>m;
    cout << min_squares(n, m) << endl;
    }
}
