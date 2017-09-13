//https://www.codechef.com/ALKH2017/problems/INCDEC

//Diphonatine equation solution exist of ax+by = c if and only if c is divisible by gcd(a,b)

//Find solution of -k1*x + k2*y = z-a[i];
// find x0 + y0
//other solutions x0 + y0 + (k1+k2)*t
//it should be same in at least y positions

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL power(LL a, LL b, LL mod) {
  LL res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b /= 2;
  }
  return res;
}

LL mod(LL a, LL b) {
  return ((a % b) + b) % b;
}
// returns d = gcd(a,b); finds x,y such that d = ax + by
LL extended_euclid(LL a, LL b, LL &x, LL &y) {
  LL xx = y = 0;
  LL yy = x = 1;
  while (b) {
    LL q = a / b;
    LL t = b; b = a % b; a = t;
    t = xx; xx = x - q * xx; x = t;
    t = yy; yy = y - q * yy; y = t;
  }
  return a;
}

LL mod_inverse(LL a, LL n) {
  LL x, y;
  LL d = extended_euclid(a, n, x, y);
  if (d > 1) return -1;
  return mod(x, n);
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<LL> A(n);
    map<LL, int> M;
    LL k1, k2, y, z;
    for (int i = 0; i < n; ++i) cin >> A[i];
    cin >> k1 >> k2 >> z >> y;
    for (auto x : A) {
      LL steps = mod(y - x, k1) * mod_inverse(k2, k1) % k1;
      steps = steps + (x + steps * k2 - y) / k1;
      M[steps % (k1 + k2)]++;
    }
    bool ok = 0;
    for (auto x : M) {
      if (x.second >= y) {
        ok = 1;
        break;
      }
    }
    puts(ok ? "YES" : "NO");
  }
  return 0;
}
