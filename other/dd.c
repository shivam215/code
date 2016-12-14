#include <iostream>
#include <climits>
using namespace std;


int min_squares(int m, int n) {
    if (m == n)
        return 1;

    static int cache[100][100]; // Automatically initialized to 0 since static

    if (m < n)
        swap(m, n);
    if (cache[m][n])
        return cache[m][n];

    int x = INT_MAX;

    for (int i = 1; i+i <= n; ++i)
        x = min(x, min_squares(m, i) + min_squares(m, n-i));

    for (int i = 1; i+i <= m; ++i)
        x = min(x, min_squares(i, n) + min_squares(m-i, n));

    return cache[m][n] = x;
}


int main() {
    int m = 6;
    int n = 5;

    cout << min_squares(m, n) << endl;
}
