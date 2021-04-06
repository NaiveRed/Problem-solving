#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int coinChange(vector<int>& coins, int amount) {
    int dp[amount + 1];  // dp[n]: The number of coin used to make up `n`
    memset(dp, 0x7f, sizeof(dp));  // Set a large number for `cannot be made up`
    dp[0] = 0;
    for (int& coin : coins)
      for (int n = coin; n <= amount; ++n) {
        // min(dp[n]: not use `coin`, dp[n-coin]+1 : use `coin`)
        dp[n] = min(dp[n], dp[n - coin] + 1);
      }
    return dp[amount] < 0x7f7f7f7f ? dp[amount] : -1;
  }
};
