#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  // Basic DP
  int rob(vector<int>& nums) {
    int s = nums.size();
    if (!s)
      return 0;
    else if (s == 1)
      return nums[0];

    vector<int> dp(s);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < s; ++i) {
      // dp: the maximum amount of money we can rob from 0~i
      // Two cases:
      // 1. rob house `i`: dp[i-2] + nums[i]
      // 2. pass house `i`: dp[i-1]
      dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }
    return dp[s - 1];
  }

  // Improve by using only 2 variable
  int rob1(vector<int>& nums) {
    int s = nums.size();
    if (!s)
      return 0;
    else if (s == 1)
      return nums[0];

    int p_prev = nums[0];
    int prev = max(nums[0], nums[1]);
    for (int i = 2; i < s; ++i) {
      int tmp = max(prev, p_prev + nums[i]);
      p_prev = prev;
      prev = tmp;  // Current answer
    }
    return prev;
  }

  // Improve by using original `nums`
  int rob2(vector<int>& nums) {
    int s = nums.size();
    if (!s)
      return 0;
    else if (s == 1)
      return nums[0];

    nums[1] = max(nums[0], nums[1]);
    for (int i = 2; i < s; ++i)
      nums[i] = max(nums[i - 1], nums[i - 2] + nums[i]);
    return nums.back();
  }
};
