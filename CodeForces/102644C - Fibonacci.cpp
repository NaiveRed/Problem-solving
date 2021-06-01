#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int mod = 1e9 + 7;

struct Matrix {
  LL m[2][2];
  LL* operator[](int i) { return m[i]; }
  Matrix operator=(Matrix a) {
    m[0][0] = a[0][0];
    m[0][1] = a[0][1];
    m[1][0] = a[1][0];
    m[1][1] = a[1][1];
    return *this;
  }
};

// Return a x b
Matrix multiply(Matrix& a, Matrix& b) {
  Matrix c;
  c[0][0] = (a[0][0] * b[0][0] + a[0][1] * b[1][0]) % mod;
  c[0][1] = (a[0][0] * b[0][1] + a[0][1] * b[1][1]) % mod;
  c[1][0] = (a[1][0] * b[0][0] + a[1][1] * b[1][0]) % mod;
  c[1][1] = (a[1][0] * b[0][1] + a[1][1] * b[1][1]) % mod;
  return c;
}

// Return a^n
Matrix power(Matrix& a, LL n) {
  Matrix c;
  // Initialize with identity matrix.
  c[0][0] = c[1][1] = 1;
  c[1][0] = c[0][1] = 0;

  while (n) {
    if (n & 1) c = multiply(c, a);
    a = multiply(a, a);
    n >>= 1;
  }
  return c;
}
int main() {
  LL n;
  scanf("%lld", &n);
  if (n <= 1) {
    printf("%lld\n", n);
    return 0;
  }
  // [F_{n}, F_{n+1}] = [F_{n-2}, F_{n-1}] [0 1]
  //                                       [1 1]
  // =>
  // [F_{n}, F_{n+1}] = [F_0, F_1] [0 1]^n
  //                               [1 1]

  // Transform matrix for the fib
  // [0 1]
  // [1 1]
  Matrix t;
  t[0][0] = 0;
  t[0][1] = t[1][0] = t[1][1] = 1;
  // t^n
  t = power(t, n);

  // [F_0, F_1] = [0, 1]
  Matrix A;
  A[0][0] = A[1][0] = A[1][1] = 0;
  A[0][1] = 1;

  printf("%lld\n", multiply(A, t)[0][0]);
  return 0;
}
