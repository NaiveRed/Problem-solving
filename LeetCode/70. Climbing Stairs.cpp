// Ref to 509. Fibonacci Number
#include <bits/stdc++.h>
using namespace std;

// Iterative bottom-up with 2 variables
// Time: O(n)
// Space: O(1)
class Solution {
 public:
  int climbStairs(int n) {
    if (n <= 2) return n;
    int res = 0, prev1 = 1, prev2 = 2;
    for (int i = 3; i <= n; ++i) {
      res = prev1 + prev2;
      prev1 = prev2;
      prev2 = res;
    }
    return res;
  }
};
