#include <bits/stdc++.h>
using namespace std;

// Method 1: Basic recursive
// Time: O(2^n)
// Space: O(n)
// We need space proportionate to N to account for the max size of the stack, in
// memory. This stack keeps track of the function calls to fib(N)
class Solution {
 public:
  int fib(int n) {
    if (!n || n == 1) return n;
    return fib(n - 1) + fib(n - 2);
  }
};

// Method 2: Recursive top-down with memo
// Time: O(n)
// Space: O(n)
class Solution1 {
 public:
  int cache[31];
  Solution1() : cache{0, 1} {}
  int memo(int n) {
    if (!n || cache[n] != 0) return cache[n];
    for (int i = 2; i <= n; ++i) cache[i] = memo(i - 1) + memo(i - 2);
    return cache[n];
  }
  int fib(int n) {
    if (!n || n == 1) return n;
    return memo(n);
  }
};

// Method 3: Iterative bottom-up with memo
// Time: O(n)
// Space: O(n)
class Solution2 {
 public:
  int fib(int n) {
    if (n <= 1) return n;
    int fib[n + 1];
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; ++i) fib[i] = fib[i - 1] + fib[i - 2];
    return fib[n];
  }
};

// Method 4: Iterative bottom-up with 2 variables
// Time: O(n)
// Space: O(1)
class Solution3 {
 public:
  int fib(int n) {
    if (n <= 1) return n;
    int current = 0, prev1 = 0, prev2 = 1;
    for (int i = 2; i <= n; ++i) {
      current = prev1 + prev2;
      prev1 = prev2;
      prev2 = current;
    }
    return current;
  }
};

// Method 5: DP with pre-build table
// Time: O(n)
// Space: O(n)
class Solution4 {
 public:
  int fib_n[31] = {0, 1};
  Solution4() {
    for (int i = 2; i < 31; ++i) fib_n[i] = fib_n[i - 1] + fib_n[i - 2];
  }

  int fib(int n) { return fib_n[n]; }
};

// Method 6: Matrix Exponentiation
// Time: O(log n)
// Space: O(log n)
// See the "UVa 10229" or "CF 102644C. Fibonacci"
