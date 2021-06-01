#include <bits/stdc++.h>
#define DEBUG
using namespace std;

// Method 1: Binary exponentiation by recursion. (bottom-up)
// Time: O(log n)
// Space: O(log n) call stack
class Solution {
 public:
  double myPow(double x, int n) {
    if (!n) return 1;
    // Use unsigned because -2147483648 will overflow
    unsigned int p = abs(n);
    double res = myPow(x, (int)p / 2);
    res = (p & 1) ? res * res * x : res * res;
    return n > 0 ? res : (1.0 / res);
  }
};

// Method 2: Binary exponentiation by tail recursion. (bottom-up?)
// Time: O(log n)
// Space: O(1) constant call stack
class Solution1 {
 public:
  double helper_tr(double x, unsigned int n, double result) {
    if (!n) return result;
    return helper_tr(x * x, n / 2, (n & 1) ? result * x : result);
  }

  double myPow(double x, int n) {
    // Use unsigned because -2147483648 will overflow
    double res = helper_tr(x, abs(n), 1);
    return n > 0 ? res : (1.0 / res);
  }
};

// Method 3: Binary exponentiation by iteration. (top-down)
// Time: O(log n)
// Space: O(1)
class Solution2 {
 public:
  double myPow(double x, int n) {
    // Use unsigned because -2147483648 will overflow
    unsigned int p = abs(n);
    // Binary Exponentiation
    double res = 1;
    while (p) {
      if (p & 1) res *= x;
      x *= x;
      p >>= 1;
    }
    return (n > 0) ? res : (1.0 / res);
  }
};
