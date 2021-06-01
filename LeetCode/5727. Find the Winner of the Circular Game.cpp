#include <bits/stdc++.h>
using namespace std;

// Method 1: Recursive, top down
class Solution {
 public:
  int find(int n, int k) {
    if (n == 1) return 0;
    return (find(n - 1, k) + k) % n;
  }
  int findTheWinner(int n, int k) { return find(n, k) + 1; }
};

// Method 2: Iterative, bottom up
class Solution1 {
 public:
  int findTheWinner(int n, int k) {
    int win = 0;
    for (int i = 2; i <= n; ++i) win = (win + k) % i;
    return win + 1;
  }
};

// Method 3: DP, build the table
class Solution2 {
 public:
  int findTheWinner(int n, int k) {
    int dp[n + 1][k + 1];
    for (int i = 0; i <= k; ++i) dp[1][k] = 0;
    for (int i = 2; i <= n; ++i)
      for (int j = 1; j <= k; ++j) dp[i][j] = (dp[i - 1][j] + j) % i;
    return dp[n][k] + 1;
  }
};
