#include <bits/stdc++.h>
using namespace std;

// Method 1: Recursive with memoization
// Time: O(n^2),
// the numTrees(n-i-1) of the loop at first call will need O(n-i-1)
// numTrees(n-i-2) ... numTrees(0) will need O(n-i-2) ... O(1).
// The outer loop at first call is O(n), thus the total time will be O(n*n).
// Space: O(n)
class Solution {
 public:
  int memo[20];
  Solution() : memo{} {}
  int numTrees(int n) {
    if (n == 1 || n == 0)
      return 1;
    else if (memo[n])
      return memo[n];
    int sum = 0;
    // The all combinations will be "(# of left nodes) root (# of right nodes)"
    // E.g., if n = 4
    // (0) root (3), (1) root (2), (2) root (1), (3) root (0)
    //    root=1                                    root=3
    // For each `i+1` as root
    for (int i = 0; i < n; ++i) sum += numTrees(i) * numTrees(n - i - 1);
    memo[n] = sum;
    return sum;
  }
};

// Method 2: DP bottom-up, same as method 1
// Time: O(n^2)
// Space: O(n)
class Solution1 {
 public:
  int numTrees(int n) {
    if (n == 1 || n == 0) return 1;
    int dp[n + 1];
    dp[0] = dp[1] = 1;
    // Use i as root
    for (int i = 2; i <= n; ++i) {
      dp[i] = 0;
      // Sum the all combinations
      for (int k = 0; k < i; ++k) dp[i] += dp[k] * dp[i - k - 1];
    }
    return dp[n];
  }
};
