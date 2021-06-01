#include <bits/stdc++.h>
using namespace std;

// Time: O(N^2)
// Space: O(N^2)
class Solution {
 public:
  bool canCross(vector<int>& stones) {
    int n = stones.size();
    // dp[n][k]: n means the index of stone, k means the jump size it can use
    // here. the maximum k will be the length-1 of size `stones` E.g.,
    // [0,1,2,3,4]: max=4
    bool dp[n][n + 1];  // n+1: for the final jump k+1
    for (int i = 0; i < n; ++i) memset(dp[i], 0, sizeof(dp[0]));
    dp[0][1] = true;

    for (int i = 1; i < n; ++i)
      for (int s = i - 1; s >= 0; --s) {
        int diff = stones[i] - stones[s];
        if (diff < n && dp[s][diff]) {
          dp[i][diff - 1] = dp[i][diff] = dp[i][diff + 1] = true;
          if (i == n - 1) return true;
        }
      }
    return false;
  }
};
