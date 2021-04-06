#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int change(int amount, vector<int>& coins) {
    // dp[n]: The number of combinations to make up `n`.
    // dp[x] = 0, means can not make up x.
    // dp[0] = `, for base case.
    int dp[amount + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int& coin : coins)
      for (int i = coin; i <= amount; ++i) dp[i] += dp[i - coin];
    return dp[amount];
  }
};
